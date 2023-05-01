% Факты о контактах
:- dynamic contact/3.
contact(dima, 84567840304, mail).
contact(roma, 88885553535, mmail).

% Правило для добавления контакта
add_contact(Name, Phone, Email) :-
    assert(contact(Name, Phone, Email)).

% Правило для удаления контакта
delete_contact(Name) :-
    retract(contact(Name, _, _)).

% Правило для поиска контакта
find_contact(Name):-
    contact(Name, Phone, Email), write(Phone), nl, write(Email).