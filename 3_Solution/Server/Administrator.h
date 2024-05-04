#pragma once
#include "AClient.h"
class Administrator : public AClient
{
protected:

public:
	Administrator() = default;
	bool listProduct() override;
	bool deleteProduct() override;
	~Administrator() = default;
};

