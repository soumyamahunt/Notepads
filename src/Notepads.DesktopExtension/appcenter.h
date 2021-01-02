#pragma once
#include "pch.h"
#include "curl/curl.h"

#ifdef  _DEBUG
#include "rapidjson/prettywriter.h"
#else
#include "rapidjson/writer.h"
#endif

namespace AppCenter
{
	using namespace boost::stacktrace;
	using namespace std;

	namespace
	{
		static struct curl_slist* headerList = NULL;
	}

	void start();
	void trackError(bool isFatal, DWORD errorCode, const string& message, const stacktrace& stackTrace);
	void trackEvent(const string& name, const vector<pair<const CHAR*, string>>& properties, const string& sid = "");
}