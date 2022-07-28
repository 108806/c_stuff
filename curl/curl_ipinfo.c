#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	CURL *curl = curl_easy_init();
	if (!curl)
	{
		fprintf(stderr, "init failed.\n");
		return EXIT_FAILURE;
	}

	//set opts
	curl_easy_setopt(curl, CURLOPT_URL, "https://ipinfo.io");
	CURLcode res = curl_easy_perform(curl);

	if (res != CURLE_OK) fprintf(stderr, 
		"curl_easy_perform() failed");

	
	curl_easy_cleanup(curl);
	return EXIT_SUCCESS;
}
