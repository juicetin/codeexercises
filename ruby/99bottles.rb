def ninety_nine_bottles
	for i in 0..98
		puts "#{99-i} bottles of beer on the wall, #{99-i} bottles of beer"
		puts "Take one down and pass it around, #{99-i-1} bottles of peer on the wall"
		puts ""
	end
end

ninety_nine_bottles
