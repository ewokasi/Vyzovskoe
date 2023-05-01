(defstruct contact
  name
  phone-number
  email)



(defvar *phonebook* ())


(defun add-contact (name phone-number email)
  (let ((contact (make-contact :name name :phone-number phone-number :email email)))
    (push (cons name contact) *phonebook*)))


(defun delete-contact (name)
  (setq *phonebook* (remove-if #'(lambda (contact) (string= (car contact) name)) *phonebook*)))


(defun find-contact (key)
  (let ((contact (assoc key *phonebook* :test #'equal)))
    (when contact
      (cdr contact))))



(add-contact "Dima" "1234321234" "qwerty")
(add-contact "Roma" "2344356" "error@error.com")



(write(find-contact "Dima"))

(delete-contact "Roma")
(delete-contact "Dima")

