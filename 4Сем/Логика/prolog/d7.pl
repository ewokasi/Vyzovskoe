% Предикат для определения ребер графа
edge(a, b).
edge(a, c).
edge(b, c).
edge(c, d).
edge(d, e).
edge(b, a). %строчка цикла

% Предикат для поиска всех возможных путей из вершины X к вершине Y
path(X, Y, [X,Y]) :- edge(X,Y).
path(X, Y, [X|P]) :- edge(X,Z), path(Z,Y,P).

% Проверка списка на уникальность элементов
is_unique(List) :- sort(List, Sorted), length(List, N), length(Sorted, N).



free:-

not(path(a,a,P)),not(path(b,b,P)),not(path(c,c,P)),not(path(d,d,P)),not(path(e,e,P)).

%free