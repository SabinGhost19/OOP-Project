#ifndef COMPANYDETAILSREQUEST_H
#define COMPANYDETAILSREQUEST_H

#include "DataRequest.h"

class CompanyDetailsRequest : public DataRequest
{
public:
    CompanyDetailsRequest();
    void ReceiveDetails();
};

#endif // COMPANYDETAILSREQUEST_H
