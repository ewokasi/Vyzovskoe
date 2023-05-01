
same_rank(yanosh, saper).
same_rank(saper, yanosh).

friend(saper, yanosh).
friend(yanosh, saper).
friend(linkman, ferenc).
friend(ferenc, linkman).
friend(saper, ferenc).
friend(ferenc, saper).
friend(andrash, layosh).

not_pilot(ferenc).
not_pilot(bela).
not_pilot(layosh).

not_linkman(ferenc).
not_linkman(layosh).

not_artilerian(layosh).

not_saper(layosh).
not_saper(ferenc).

grater(yanosh, layosh).
grater(bela, ferenc).


can_be_colonel(X):- not(same_rank(X, Y)).
lower_rank(X):- not(grater(X, Y)).

colonel(X):- can_be_colonel(X), not(lower_rank(X)).

major(X):- (same_rank(X, Y)); grater(Z, X), colonel(Z).

captain(X):- not(same_rank(X, Y)), grater(Z,X), major(Z).


pilot(X):- not(not_pilot(X)), not(marine(X)).

saper(X):- not(not_saper(X)), not(grater(X, Z)), not(pilot(X)), not(marine(X)), not(artilerian(X)).

linkman(X):- not(saper(X)), not(pilot(X)), not(not_linkman(X)).

marine(X):- not_saper(X), not_artilerian(X), not_linkman(X), not_pilot(X).

artilerian(X):- not(saper(X)), not(pilot(X)), not(not_artilerian(X)), not(marine(X)), not(linkman(X)).


check_name(Name, Predicate) :-
  current_predicate(Predicate/1), % проверяем, что предикат существует
  call(Predicate, Name), % вызываем предикат с именем в качестве аргумента
  write(Name), write(' is a '), write(Predicate), nl. % выводим результат в консоль

  % создание списка имен и предикатов
names([bela, ferenc, layosh, andrash, yanosh]).
predicates([colonel, major, captain, artilerian, saper, linkman, marine, pilot]).

% цикл по спискам
loop:-
  names(Names), % получаем список имен
  predicates(Predicates), % получаем список предикатов
  member(Name, Names), % выбираем имя из списка
  member(Predicate, Predicates), % выбираем предикат из списка
  check_name(Name, Predicate), 
  fail. 

