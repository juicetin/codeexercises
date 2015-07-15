var prev = 1;
var curr = 1;
var sum = 0;

while (1) {
	var tmp = curr;
	curr = prev + curr;
	prev = tmp;
	if (curr < 4000000) {
		if (curr % 2 == 0)
			sum += curr;
		print(curr);
	}
	else {
		break;
	}
}

print(sum);
