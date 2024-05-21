#define _CRT_SECURE_NO_WARNINGS
#include "ReviewRequest.h"
#include "APPServer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ReviewRequest::ReviewRequest()
{
    this->review = nullptr;
}

void ReviewRequest::addReview(int productID)
{
    int recvBytes = 0, sentBytes = 0;
    char comment[1000];
    char ratingChar[10];
    std::string ratingString;
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(ratingChar, sizeof(ratingChar));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    ratingChar[recvBytes] = '\0';
    ratingString = ratingChar;
    int ratingInt = std::stoi(ratingString);
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(comment, sizeof(comment));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    comment[recvBytes] = '\0';
    int clientID = APPServer::getInstance()->getManagedClient()->getClintId();
    APPServer::getInstance()->getBDComm()->addReview(clientID, productID, ratingInt, comment);
    this->review = new Reviews;
    this->review->setClientID(clientID);
    this->review->setRating(ratingInt);
    this->review->setComment(comment);
    for (auto iterator : APPServer::getInstance()->getListedProducts())
        if (iterator->getProductId() == productID)
            iterator->addReview(this->review);
}

void ReviewRequest::sendReviews(int productID)
{
    char ackBuffer[10];
    int recvBytes = 0, sentBytes = 0;
    vector<Reviews*> productReviews;
    for (auto iterator : APPServer::getInstance()->getListedProducts())
        if (iterator->getProductId() == productID)
        {
            productReviews = iterator->getReviews();
            break;
        }
    int nrOfReviewsInt = productReviews.size();
    std::string nrOfReviewsString = std::to_string(nrOfReviewsInt);
    sentBytes = APPServer::getInstance()->getTcpServer()->send(nrOfReviewsString.c_str(), nrOfReviewsString.size());
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
    for (auto iterator : productReviews)
    {
        char clientNames[100] = "";
        strcpy(clientNames, APPServer::getInstance()->getBDComm()->getClientNamesByID(iterator->getClientID()));
        sentBytes = APPServer::getInstance()->getTcpServer()->send(clientNames, strlen(clientNames));
        recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
        int reviewRatingInt = iterator->getRating();
        std::string reviewRatingString = std::to_string(reviewRatingInt);
        sentBytes = APPServer::getInstance()->getTcpServer()->send(reviewRatingString.c_str(), reviewRatingString.size());
        recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
        char* comment=nullptr;
        comment = iterator->getComment();        
        sentBytes = APPServer::getInstance()->getTcpServer()->send(comment, strlen(comment));
        recvBytes = APPServer::getInstance()->getTcpServer()->recv(ackBuffer, sizeof(ackBuffer));
    }
}

bool ReviewRequest::receiveRequest()
{
    int sentBytes = 0, recvBytes = 0;
    char productIDChar[10];
    char request[10];
    char action;
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(request, sizeof(request));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    request[recvBytes] = '\0';
    recvBytes = APPServer::getInstance()->getTcpServer()->recv(productIDChar, sizeof(productIDChar));
    sentBytes = APPServer::getInstance()->getTcpServer()->send("ACK", strlen("ACK"));
    productIDChar[recvBytes] = '\0';
    std::string productIDString = productIDChar;
    int productIDInt = std::stoi(productIDString);
    action = request[0];
    switch (action)
    {
    case '1':
        cout << "TRYING TO GET REVIEWS FOR PRODUCT: " << productIDInt << endl;
        this->sendReviews(productIDInt);
        cout << "REVIEWS HAS BEEN SENT FOR THE SELECTED PRODUCT" << endl;
        return true;
    case '2':
        cout << "TRYING TO ADD REVIEW FOR PRODUCT: " << productIDInt << endl;
        this->addReview(productIDInt);
        cout << "REVIEW HAS BEEN ADDED TO THE SELECTED PRODUCT" << endl;
        return true;
    default:
        cout << "REVIEW HAS NOT BEEN ADDED" << endl;
        return false;
    }
}

bool ReviewRequest::sendAnswear()
{
    return true;
}

ReviewRequest::~ReviewRequest()
{
    this->review = nullptr;
}
