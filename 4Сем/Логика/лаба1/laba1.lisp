; функция сложения двух комплексных чисел
(defun AddCom(Com1 Com2)
   (cons (+ (car Com1)(car Com2))
(cons (+ (cadr Com1)(cadr Com2)) NIL)))
; функция вычитания двух комплексных чисел
(defun SubCom(Com1 Com2)
   (cons (- (car Com1)(car Com2))
(cons (- (cadr Com1)(cadr Com2)) NIL)))
; функция сравнения двух комплексных чисел
(defun EqCom(Com1 Com2)
   (and (= (car Com1)(car Com2))
        (= (cadr Com1)(cadr Com2))))
; функция умножения двух комплексных чисел
(defun MultCom(Com1 Com2)
   (cons (- (* (car Com1)(car Com2))
            (* (cadr Com1)(cadr Com2)))
       (cons (+ (* (car Com1)(cadr Com2))
                (* (cadr Com1)(car Com2)))  NIL)))
; функция деления комплексных чисел
(defun DivCom(Com1 Com2)
  (let ((z (+ (* (car Com2)(car Com2))
              (* (cadr Com2)(cadr Com2))) ))
     (cons (/ (+ (* (car Com1)(car Com2))
               z)(* (cadr Com1)(cadr Com2)))
       (cons (/ (- (* (cadr Com1)(car Com2))
                z) (* (car Com1)(cadr Com2)))
NIL ))))
; вычисление суммы чисел 2+3i и 1.5-8i 
(AddCom '(2 3) '(1.5 -8))
; вычисление произведения чисел 3-i и 3+i 
(MultCom '(3 -1) '(3 1))