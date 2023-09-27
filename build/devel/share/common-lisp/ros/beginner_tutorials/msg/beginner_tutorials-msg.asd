
(cl:in-package :asdf)

(defsystem "beginner_tutorials-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "smsg" :depends-on ("_package_smsg"))
    (:file "_package_smsg" :depends-on ("_package"))
  ))