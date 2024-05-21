#pragma once
#include "ARequest.h"
#include "Reviews.h"

class ReviewRequest : public ARequest
{
private:
	Reviews* review;
public:
	ReviewRequest();
	void addReview(int productID);
	void sendReviews(int productID);
	bool receiveRequest() override;
	bool sendAnswear() override;
	~ReviewRequest();
};

