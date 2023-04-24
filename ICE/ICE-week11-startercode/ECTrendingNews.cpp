#include "ECTrendingNews.h"

// Your code goes here
// pay-per click subscriber
// ECPayPerClickSubscriber 


void ECPayPerClickSubscriber :: Update()
{
    news.ReceivePayment(1);
}

// Contract subscriber
// ECContractSubscriber 
// ECContractSubscriber :: ECContractSubscriber(ECTrendingNews &news) : news(news) {}
	// ECPayPerClickSubscriber(ECTrendingNews &news) : news(news) {}

