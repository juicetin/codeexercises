class Student
	attr_accessor :first_name, :last_name, :primary_phone_number

# 	def introduction
# 		puts "Hi, I'm #{first_name}!"
# 	end

	def introduction(target)
		puts "Hi #{target}, I'm #{first_name}!"
	end

	def fav_number
		7
	end
end

frank = Student.new
name = gets.chomp
frank.first_name = name
frank.introduction("Arch Linux User")
puts frank.fav_number

