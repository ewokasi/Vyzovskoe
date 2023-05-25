:- dynamic abonent/4.

% добавление абонента
add_abonent(Name, Number, Service1, Service2) :-
    assertz(abonent(Name, Number, Service1, Service2)).

% удаление абонента
remove_abonent(Number) :-
    retract(abonent(_, Number, _, _)).

% поиск абонента по номеру телефона
find_abonent(Number) :-
    abonent(Name, Number, Service1, Service2),
    format('Abonent: ~w\nNumber: ~w\nservice 1: ~w\nservice 2: ~w\n', [Name, Number, Service1, Service2]).

% вывод всех абонентов
list_abonents :-
    abonent(Name, Number, Service1, Service2),
    format('Abonent: ~w\nNumber: ~w\nservice 1: ~w\nservice 2: ~w\n', [Name, Number, Service1, Service2]).

%add_abonent(дима, 8996, 1,1).
%add_abonent(рома, 1223, 0,0).
%find_abonent(1223).
%list_abonents.