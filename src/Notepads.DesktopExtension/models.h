#pragma once
#include "pch.h"
#include "resource.h"
#include "rapidjson/document.h"

namespace AppCenter
{
	using namespace fmt;
	using namespace rapidjson;
	using namespace std;
	using namespace winrt;
	using namespace Windows::Security::ExchangeActiveSyncProvisioning;
	using namespace Windows::System::Profile;

	class Exception
	{
	public:
		Exception(const string& message) : _message(message) {}
		Exception(const string& message, const string& stackTrace) : _message(message), _stackTrace(stackTrace) {}
		Exception(const Exception& exception) : _message(exception._message), _stackTrace(exception._stackTrace) {}
		Exception(const exception& exception) : _message(exception.what()) {}

		~Exception() {}

		Exception& operator=(const Exception& exception)
		{
			if (this == &exception) return *this;

			_type = exception._type;
			_message = exception._message;
			_stackTrace = exception._stackTrace;
			return *this;
		}

		template <typename Writer>
		void Serialize(Writer& writer) const
		{
			writer.StartObject();

			writer.String("type");
			writer.String(_type.c_str(), static_cast<SizeType>(_type.length()));
			writer.String("message");
			writer.String(_message.c_str(), static_cast<SizeType>(_message.length()));
			writer.String("stackTrace");
			writer.String(_stackTrace.c_str(), static_cast<SizeType>(_stackTrace.length()));

			writer.EndObject();
		}

	private:
		string _type = "Win32Exception";
		string _message;
		string _stackTrace = "";
	};

	class Device
	{
	public:
		Device()
		{
			HMODULE handle = ::GetModuleHandle(NULL);
			HRSRC rc = FindResource(handle, MAKEINTRESOURCE(APPCENTER_JSON), MAKEINTRESOURCE(JSONFILE));
			HGLOBAL rcData = LoadResource(handle, rc);
			DWORD size = SizeofResource(handle, rc);
			Document versionData;
			versionData.Parse(static_cast<char*>(LockResource(rcData)));
			_appVersion = versionData["appVersion"].GetString();
			_appBuild = versionData["appBuild"].GetString();
			_sdkVersion = versionData["sdkVersion"].GetString();

			EasClientDeviceInformation oemInfo = EasClientDeviceInformation();
			_osName = to_string(oemInfo.OperatingSystem());

			ULONGLONG version = stoull(AnalyticsInfo::VersionInfo().DeviceFamilyVersion().c_str());
			ULONGLONG major = (version & 0xFFFF000000000000L) >> 48;
			ULONGLONG minor = (version & 0x0000FFFF00000000L) >> 32;
			ULONGLONG build = (version & 0x00000000FFFF0000L) >> 16;
			ULONGLONG revision = (version & 0x000000000000FFFFL);
			_osVersion = format("{}.{}.{}", major, minor, build);
			_osBuild = format("{}.{}.{}.{}", major, minor, build, revision);

			_model = to_string(oemInfo.SystemProductName());
			_oemName = to_string(oemInfo.SystemManufacturer());

			RECT desktop;
			GetWindowRect(GetDesktopWindow(), &desktop);
			_screenSize = format("{}x{}", desktop.right, desktop.bottom);

			WCHAR locale[LOCALE_NAME_MAX_LENGTH + 1];
			LCIDToLocaleName(GetThreadLocale(), locale, LOCALE_NAME_MAX_LENGTH, 0);
			WCHAR localeDisplayName[LOCALE_NAME_MAX_LENGTH + 1];
			GetLocaleInfoEx(locale, LOCALE_SENGLISHDISPLAYNAME, localeDisplayName, LOCALE_NAME_MAX_LENGTH);
			_locale = to_string(locale);

			TIME_ZONE_INFORMATION timeZoneInfo;
			GetTimeZoneInformation(&timeZoneInfo);
			_timeZoneOffset = -1 * timeZoneInfo.Bias;
		}

		Device(const Device& device) :
			_appVersion(device._appVersion), _appBuild(device._appBuild), _sdkVersion(device._sdkVersion),
			_osName(device._osName), _osVersion(device._osVersion), _osBuild(device._osBuild),
			_model(device._model), _oemName(device._oemName), _screenSize(device._screenSize),
			_locale(device._locale), _timeZoneOffset(device._timeZoneOffset) {}

		~Device() {}

		Device& operator=(const Device& device)
		{
			if (this == &device) return *this;

			_appNamespace = device._appNamespace;
			_appVersion = device._appVersion;
			_appBuild = device._appBuild;
			_sdkName = device._sdkName;
			_sdkVersion = device._sdkVersion;
			_osName = device._osName;
			_osVersion = device._osVersion;
			_osBuild = device._osBuild;
			_model = device._model;
			_oemName = device._oemName;
			_screenSize = device._screenSize;
			_locale = device._locale;
			_timeZoneOffset = device._timeZoneOffset;
			return *this;
		}

		template <typename Writer>
		void Serialize(Writer& writer) const
		{
			writer.StartObject();

			writer.String("appNamespace");
			writer.String(_appNamespace.c_str(), static_cast<SizeType>(_appNamespace.length()));
			writer.String("appVersion");
			writer.String(_appVersion.c_str(), static_cast<SizeType>(_appVersion.length()));
			writer.String("appBuild");
			writer.String(_appBuild.c_str(), static_cast<SizeType>(_appBuild.length()));
			writer.String("sdkName");
			writer.String(_sdkName.c_str(), static_cast<SizeType>(_sdkName.length()));
			writer.String("sdkVersion");
			writer.String(_sdkVersion.c_str(), static_cast<SizeType>(_sdkVersion.length()));
			writer.String("osName");
			writer.String(_osName.c_str(), static_cast<SizeType>(_osName.length()));
			writer.String("osVersion");
			writer.String(_osVersion.c_str(), static_cast<SizeType>(_osVersion.length()));
			writer.String("osBuild");
			writer.String(_osBuild.c_str(), static_cast<SizeType>(_osBuild.length()));
			writer.String("model");
			writer.String(_model.c_str(), static_cast<SizeType>(_model.length()));
			writer.String("oemName");
			writer.String(_oemName.c_str(), static_cast<SizeType>(_oemName.length()));
			writer.String("screenSize");
			writer.String(_screenSize.c_str(), static_cast<SizeType>(_screenSize.length()));
			writer.String("locale");
			writer.String(_locale.c_str(), static_cast<SizeType>(_locale.length()));
			writer.String("timeZoneOffset");
			writer.Uint(_timeZoneOffset);

			writer.EndObject();
		}

		string getOsVersion()
		{
			return _osBuild;
		}

	private:
		string _appNamespace = "Notepads.DesktopExtension";
		string _appVersion;
		string _appBuild;
		string _sdkName = "appcenter.uwp";
		string _sdkVersion;
		string _osName;
		string _osVersion;
		string _osBuild;
		string _model;
		string _oemName;
		string _screenSize;
		string _locale;
		unsigned _timeZoneOffset;
	};
}