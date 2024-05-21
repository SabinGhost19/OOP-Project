#pragma once
#include "ARequest.h"
#include <vector>

using namespace std;

class ImageRequest : public ARequest
{
private:
	vector<char*> imagesPaths;
public:
	ImageRequest();
	bool receiveRequest() override;
	bool sendAnswear() override;
	~ImageRequest();
};

