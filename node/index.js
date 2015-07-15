var Hapi = require('hapi');
var Good = require('good');

var knex = require('knex') ({
	client: 'pg',
	connection: {
		user: 'postgres',
		database: 'myDatabase',
		port: 5432,
		// host: 'localhost',
		// password: ''
	},
	debug: false
});

var server = new Hapi.Server();
server.connection({ port: 3000 });

server.route({
	method: 'GET',
	path: '/',
	handler: function (request, reply) {
		reply('Hello, world!');
	}
});

server.route({
	method: 'GET',
	path: '/{name}',
	handler: function (request, reply) {
		// reply('Hello, ' + encodeURIComponent(request.params.name) + '!');
		// reply('Test');
		// reply(knex.select().table('weather'));
		reply(knex.select('city', 'prcp').from('weather'));
	}
});

server.register({
	register: Good,
	options: {
		reporters: [{
			reporter: require('good-console'),
			events: {
				response: '*',
				log: '*'
			}
		}]
	}
}, function (err) {
	if (err) {
		throw err; // something bad happened loading the plugin
	}

	server.start(function () {
		server.log('info', 'Server running at: ' + server.info.uri);
	});
});
