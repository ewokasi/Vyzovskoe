%варик 59

not_in(a, doj).
not_in(b , ftc).
not_placed(doj, 1).
placed(ftc , 1).
placed(ftc, 2).
not_placed(vashah, 2).

placed(X, Y):-not(not_placed(X, Y)).

in(c, X):- placed(X, 3).
in(a, X):- placed(X, 1), not(not_in(a, X)), not(not_placed(X, 2)).
in(b, X):- (placed(X, 1); placed(X, 2)), not(not_in(b, X)).
in(a, X):- placed(X, 3), not(not_in(a, X)).



start:-
write('------------Places-------------'), nl,
write('____________doj - '), (placed(doj, 1), write('1 '));(placed(doj, 2), write('2 '));(placed(doj, 3), write('3 ')), nl,
write('____________ftc - '), (placed(ftc, 1), write('1 ')); (placed(ftc, 2), write('2 ')); (placed(ftc, 3), write('3 ')), nl,
write('____________vashah - '), (placed(vashah, 2), write('2 ')); (placed(vashah, 3), write('3 ')), nl,
write('---------in Team--------------'), nl,
write('____________a - '), (in(a , doj), write('doj ')); (in(a , ftc), write('ftc ')); (in(a , vashah), write('vashah')), nl,
write('____________b - '), (in(b , doj), write('doj ')); (in(b , ftc), write('ftc ')); (in(b , vashah), write('vashah')), nl,
write('____________c - '), (in(c , vashah), write('vashah'));(in(c , ftc), write('ftc ')),write('-----------'), nl.