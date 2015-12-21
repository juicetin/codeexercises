fish(perch). % Perch is a fish.
fish(salmon). % Salmon is a fish.

likes(mary, food).
likes(mary, wine).
likes(john, wine).
likes(john, mary).

asdfBird.
animal(asdfBird).
winged(asdfBird).

bird(X) :- animal(X), winged(X).
evil(X) :- intendsToHaveNuclearWeapons(X).

father(john, sue).
mother(mary, sue).

mother(anne,john).
mother(sonia,mary).
father(bill,john).
father(charles,mary).

parent(X,Y) :- father(X,Y).
parent(X,Y) :- mother(X,Y).
grandparent(X,Y) :- parent(X,Z) ,parent(Z,Y).

