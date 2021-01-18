﻿namespace Notepads.Settings
{
    internal static class SettingsKey
    {
        // App related
        internal static string AppVersionStr = "AppVersionStr";
        internal static string IsJumpListOutOfDateBool = "IsJumpListOutOfDateBool";
        internal static string ActiveInstanceIdStr = "ActiveInstanceIdStr";
        internal static string ExitingLastTabClosesWindowBool = "ExitingLastTabClosesWindowBool";
        internal static string AlwaysOpenNewWindowBool = "AlwaysOpenNewWindowBool";

        // Theme related
        internal const string RequestedThemeStr = "RequestedThemeStr";
        internal const string AppBackgroundTintOpacityDouble = "AppBackgroundTintOpacityDouble";
        internal const string AppAccentColorHexStr = "AppAccentColorHexStr";
        internal const string CustomAccentColorHexStr = "CustomAccentColorHexStr";
        internal const string UseWindowsAccentColorBool = "UseWindowsAccentColorBool";

        // Editor related
        internal const string EditorFontFamilyStr = "EditorFontFamilyStr";
        internal const string EditorFontSizeInt = "EditorFontSizeInt";
        internal const string EditorFontStyleStr = "EditorFontStyleStr";
        internal const string EditorFontWeightUshort = "EditorFontWeightUshort";
        internal const string EditorDefaultTextWrappingStr = "EditorDefaultTextWrappingStr";
        internal const string EditorDefaultLineHighlighterViewStateBool = "EditorDefaultLineHighlighterViewStateBool";
        internal const string EditorDefaultLineEndingStr = "EditorDefaultLineEndingStr";
        internal const string EditorDefaultEncodingCodePageInt = "EditorDefaultEncodingCodePageInt";
        internal const string EditorDefaultDecodingCodePageInt = "EditorDefaultDecodingCodePageInt";
        internal const string EditorDefaultUtf8EncoderShouldEmitByteOrderMarkBool = "EditorDefaultUtf8EncoderShouldEmitByteOrderMarkBool";
        internal const string EditorDefaultTabIndentsInt = "EditorDefaultTabIndentsInt";
        internal const string EditorDefaultSearchEngineStr = "EditorDefaultSearchUrlStr";
        internal const string EditorCustomMadeSearchUrlStr = "EditorCustomMadeSearchUrlStr";
        internal const string EditorShowStatusBarBool = "EditorShowStatusBarBool";
        internal const string EditorEnableSessionBackupAndRestoreBool = "EditorEnableSessionBackupAndRestoreBool";
        internal const string EditorHighlightMisspelledWordsBool = "EditorHighlightMisspelledWordsBool";
        internal const string EditorDefaultDisplayLineNumbersBool = "EditorDefaultDisplayLineNumbersBool";
        internal const string EditorEnableSmartCopyBool = "EditorEnableSmartCopyBool";

        // Interop related
        // These values depend upon constant fields described in ..\Notepads.DesktopExtension\pch.h.
        // Changing value in one place require changing variable with similar name in another.
        internal const string AppCenterSecret = null;
        internal const string PackageSidStr = "PackageSidStr";
        internal const string AppCenterInstallIdStr = "AppCenterInstallIdStr";
        internal const string LastChangedSettingsKeyStr = "LastChangedSettingsKeyStr";
        internal const string LastChangedSettingsAppInstanceIdStr = "LastChangedSettingsAppInstanceIdStr";
        internal const string LaunchElevetedProcessSuccessStr = "LaunchElevetedProcessSuccess";
        internal const string LaunchElevetedProcessFailedStr = "LaunchElevetedProcessFailed";
        internal const string ExtensionProcessLifetimeObjNameStr = "ExtensionProcessLifetimeObj";
        internal const string ElevatedProcessLifetimeObjNameStr = "ElevatedProcessLifetimeObj";
        internal const string ExtensionUnblockEventNameStr = "NotepadsExtensionUnblockEvent";
        internal const string ElevatedWriteEventNameStr = "NotepadsElevatedWriteEvent";
        internal const string ElevatedRenameEventNameStr = "NotepadsElevatedRenameEvent";
        internal const string ExtensionUnblockPipeConnectionNameStr = "NotepadsExtensionUnblockPipe";
        internal const string ElevatedWritePipeConnectionNameStr = "NotepadsElevatedWritePipe";
        internal const string ElevatedRenamePipeConnectionNameStr = "NotepadsElevatedRenamePipe";
    }
}