%из 2 условия задачи d может быть только 1м, иначе назад будет передвинуто 4, что противоречит условию

:-dynamic second/2.
second(a, 5).
second(a, 6).
second(a, 7).
second(b, 6).
second(c, 7).
second(d, 1).
second(e, 1).
second(e, 2).
second(f, 1).
second(f, 2).
second(f, 3).
second(g, 1).
second(g, 2).
second(g, 3).
second(g, 4).
%первое условие задачи
first(a, 1).
first(b, 2).
first(c, 3).
first(d, 4).
first(e, 5).
first(f, 6).
first(g, 7).

place1(X):- second(X, 1), not(first(X, 1)), retract(second(X, 1)).
place2(X):- second(X, 2), not(first(X, 2)), retract(second(X, 2)).
place3(X):- second(X, 3), not(first(X, 3)), retract(second(X, 3)).
place4(X):- second(X, 4), not(first(X, 4)), retract(second(X, 4)).
place5(X):- second(X, 5), not(first(X, 5)), retract(second(X, 5)).
place6(X):- second(X, 6), not(first(X, 6)), retract(second(X, 6)).
place7(X):- second(X, 7), not(first(X, 7)), retract(second(X, 7)).


members([d,e,f,g,a,b,c]).
predicates([place7, place6, place5, place4, place3, place2, place1]).

check_name(Name, Predicate) :-
  current_predicate(Predicate/1), 
  call(Predicate, Name), 
  
  write(Name), write(' is a '), write(Predicate), nl,
  retract(second(Name,Y)).
  
%прошрамма выдает один из возможных исходов. нельзя однозначно определить, на каком месте будут спорстмены A-C так как информации недростаточно
answ:-
    members(Names),
    predicates(Predicates),
     member(Name, Names), 
  member(Predicate, Predicates), 
  check_name(Name, Predicate), 
  fail. 