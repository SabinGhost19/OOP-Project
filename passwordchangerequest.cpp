#include "passwordchangerequest.h"
#include "APPClient.h"

PasswordChangeRequest::PasswordChangeRequest() {}

void PasswordChangeRequest::SetPass(std::string pass_p){
    this->new_pass=pass_p;
}

void PasswordChangeRequest::SendPass(){
    this->message="9";
    this->Request();
    this->message=this->new_pass;
    this->Request();
}
