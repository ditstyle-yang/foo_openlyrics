#include "stdafx.h"

#define OPENLYRICS_VERSION "1.7-dev"

// Declaration of your component's version information
// Since foobar2000 v1.0 having at least one of these in your DLL is mandatory to let the troubleshooter tell different versions of your component apart.
// Note that it is possible to declare multiple components within one DLL, but it's strongly recommended to keep only one declaration per DLL.
// As for 1.1, the version numbers are used by the component update finder to find updates; for that to work, you must have ONLY ONE declaration per DLL. If there are multiple declarations, the component is assumed to be outdated and a version number of "0" is assumed, to overwrite the component with whatever is currently on the site assuming that it comes with proper version numbers.

// Copied from the DECLARE_COMPONENT_VERSION(NAME,VERSION,ABOUT) macro, defined in foo_SDK/foobar2000/SDK/component_version.h
namespace
{
    class OpenLyricsVersion : public componentversion
    {
        public:
            void get_file_name(pfc::string_base& out) final {out = core_api::get_my_file_name();}
            void get_component_name(pfc::string_base & out) final {out = "OpenLyrics";}
            void get_component_version(pfc::string_base & out) final {out = OPENLYRICS_VERSION;}
            void get_about_message(pfc::string_base & out) final;
    };
    static service_factory_single_t<OpenLyricsVersion> g_openlyricsversion_factory;
}
void OpenLyricsVersion::get_about_message(pfc::string_base & out)
{
    out = "foo_openlyrics " OPENLYRICS_VERSION "\n";
    out += "Open-source lyrics retrieval and display\n";
    out += "Source available at https://github.com/jacquesh/foo_openlyrics\n";
    out += "You can support development at https://www.buymeacoffee.com/jacquesheunis\n";
    out += "\nChangelog:\n";
    out += "Version " OPENLYRICS_VERSION " (" __DATE__ "):\n"
    "- Add a source for metal-archives.com\n"
    "- Fix retrieval failing from some sources when no 'album' tag is present\n"
    "- Fix crash when deleting lyrics from tags via the playlist context menu\n"
    "- Fix LRC offset tags being ignored if they contained a space\n"
    "\n";
    out += "Version 1.6 (2023-04-13):\n"
    "- Fix crash on startup when running on fb2k v2, beta 31 or earlier\n"
    "\n";
    out += "Version 1.5 (2023-04-03):\n"
    "- Add basic support for network music streams\n"
    "- Allow subdirectories (with '\\') in the 'file name format' save setting\n"
    "- Add support for continuously scrolling synced lyrics\n"
    "- Allow configuring line scroll time and highlight fade time separately\n"
    "- Add dark mode support to the preferences pages and some dialogs\n"
    "- Bulk searches now add to the search queue instead of creating a new one\n"
    "- Avoid saving lyrics if they're loaded from a local source during search\n"
    "- Add support for asking users to submit once-off usage metrics\n"
    "- Restrict the scroll time setting to increments of 20ms\n"
    "- Update foobar2k SDK to version 20221116\n"
    "- The lyric editor now respects fb2k's configured 'Default' font\n"
    "- Fix failing to load lyrics from meta tags in some situations\n"
    "- Fix lyrics being mangled when loaded from UTF-16-encoded text\n"
    "\n";
    out += "Version 1.4 (2022-11-19):\n"
    "- Fix always opening lyrics in explorer instead of the default file browser\n"
    "- Fix LRC line-merge options reordering lines when saving unsynced lyrics\n"
    "- Fix manual search always failing if no track is playing\n"
    "- Fix bulk search not saving lyrics when auto-save is disabled\n"
    "- Fix 'Remove all blank lines' skipping lines with certain blank characters\n"
    "\n";
    out += "Version 1.3 (2022-10-13):\n"
    "- Add 'Search manually' to the playlist context menu\n"
    "- Add 'Edit lyrics' to the playlist context menu\n"
    "- Add 'Mark as instrumental' to the playlist context menu\n"
    "- Add 64-bit build configuration\n"
    "- Move the playlist context menu entries into the OpenLyrics submenu\n"
    "- Improve clarity of the confirmation text for 'Mark as instrumental'\n"
    "- Delay lyric search when results aren't visible (e.g fb2k is minimised)\n"
    "- Fix accidentally deleting newlines from genius, azlyrics & darklyrics\n"
    "- Fix the AZLyrics source not returning lyrics available on the site\n"
    "- Fix 'Invalid path syntax' error when saving lyrics to network share\n"
    "- Fix manual search results sometimes not showing up in the result list\n"
    "- Fix 'Collapse multiple instances of the same line' option being ignored\n"
    "- Fix ColumnsUI warning that the openlyrics panel is visible on creation\n"
    "- Fix the QQMusic source reliably failing to find any lyrics\n"
    "- Update ColumnsUI SDK to version 7.0.0 beta 2\n"
    "- Update foobar2k SDK to version 20220810\n"
    "- Change preferences nomenclature from 'ID3 tags' to 'Metadata tags'\n"
    "- Re-word preferences for local files from 'save' to 'storage' folder\n"
    "- Replace the internal HTML parser for MIT license compatibility\n"
    "- Add a status bar description for the 'Remove timestamps' auto-edit\n"
    "\n";
    out += "Version 1.2 (2022-05-28):\n"
    "- Add some additional info to the debug logs for searching & saving\n"
    "- Fix failing to load the last line of lyrics\n"
    "- Fix empty lines being ignored by the editor\n"
    "\n";
    out += "Version 1.1 (2022-05-21):\n"
    "- Add an auto-edit for deleting the currently-loaded lyrics\n"
    "- Add an auto-edit for removing timestamps from synced lyrics\n"
    "- Support concurrently highlighting multiple lines with identical times\n"
    "- Add an option to enable additional debug logging\n"
    "- Rename the 'ID3 tags' source to 'Metadata tags'\n"
    "- The 'Metadata tags' source is now enabled by default\n"
    "- Change the default save tag for better compatibility with other players\n"
    "- Auto-edits that edit timestamps are now disabled for unsynced lyrics\n"
    "- Search auto-skip now also updates its metadata after searching\n"
    "- 'Mark as instrumental' now forces an auto-skip instead of creating lyrics\n"
    "- Make the input field order for manual search consistent with the results\n"
    "- No longer automatically add a space to synced & empty lyric lines\n"
    "- Fix the editor failing to parse tags from synced lyrics for offsetting\n"
    "- Fix some sources failing to search for tags with non-ASCII characters\n"
    "\n";
    out += "Version 1.0 (2022-02-15):\n"
    "- Allow manual offset of the automatic scroll with mouse drag or wheel\n"
    "- Support loading lyrics encoded as something other than UTF-8\n"
    "- Skip the anti-flood delay when only local sources are bulk-searched\n"
    "- Make the Musixmatch token text field hidden by default\n"
    "- Significantly improve Musixmatch error logging\n"
    "- Support more than exactly 2 decimal places in timestamps\n"
    "- Fix a freeze when closing the lyric panel while a search/editor is open\n"
    "- Fix the auto-search skip continuing to happen after lyrics are found\n"
    "- Fix mishandling of timestamps that include an hour as [hh:mm:ss.xx]\n"
    "\n";
    out += "Version 0.10 (2021-10-31):\n"
    "- Add a bulk search option to the playlist context menu\n"
    "- Allow sorting the manual search result list by any column\n"
    "- Allow applying lyrics from manual search without closing the dialog\n"
    "- Avoid auto-searching a track after a while if it keeps failing\n"
    "- Support applying a manual search result by double-clicking it\n"
    "- Remember modified column widths in the manual search table UI\n"
    "- Stop automatically sanitising custom save directory to a valid path\n"
    "- Make auto-searches case-insensitive when matching track metadata\n"
    "- Fix ColumnsUI config export complaints of corrupted file\n"
    "- Fix vertical alignment of lyrics being slightly off (too high)\n"
    "\n"
    "Version 0.9 (2021-08-30):\n"
    "- Add an auto-edit to 'fix' the capitalisation of each lyric line\n"
    "- Add config to apply some auto-edits to lyrics from the internet\n"
    "- Add an auto-edit to fix slightly-malformed LRC timestamps\n"
    "- Add an option to disable collapsing of duplicate timestamped lines\n"
    "- Add an option to only save unsynced lyrics\n"
    "- Change search to consider only the first instance of duplicate tags\n"
    "- Revert edit behaviour back to always auto-save (regardless of config)\n"
    "- Reduce the number of results requested when searching QQMusic\n"
    "- Add slightly more information to the musixmatch token help dialog\n"
    "- Stop silently fixing & loading slightly-malformed timestamps\n"
    "- Auto-search can now find lyrics when the source provides no album\n"
    "- Automatically highlight the first manual search result\n"
    "- Manual searches now query sources in parallel\n"
    "- Fix the text alignment bounds when using manual scrolling\n"
    "- Fix Musixmatch sometimes erroneously returning empty lyrics\n"
    "- Fix accepting (and displaying) empty lyrics from local files\n"
    "- Fix lyrics being re-saved when loaded from another local source\n"
    "- Fix lyrics not saving to tags if there was already a lyric tag\n"
    "\n"
    "Version 0.8 (2021-07-25):\n"
    "- Add a source for Musixmatch\n"
    "- Add an auto-edit to fix HTML-encoded characters (e.g &gt; to >)\n"
    "- Add an option to entirely disable auto-saving downloaded lyrics\n"
    "- Add a manual save button to the lyric panel context menu\n"
    "- Add a manual/custom lyric search dialog which searches all sources\n"
    "- Add the option to disable automatic scroll and drag/mousewheel instead\n"
    "- Change trailing bracket removal to also apply to artists & albums\n"
    "- Change edits to only auto-save if allowed by the auto-save config\n"
    "- Change the darklyrics search to check the track name not number\n"
    "- Change the default enabled sources to include QQMusic and NetEase\n"
    "- Fix search sometimes ignoring the 'exclude trailing brackets' setting\n"
    "- Fix hiding the first lines of lyrics when they look like '[text:text]'\n"
    "\n"
    "Version 0.7 (2021-07-04):\n"
    "- Add a source for QQ Music\n"
    "- Add a source for darklyrics.com\n"
    "- Add an auto-edit for removing duplicate blank lines\n"
    "- Open the lyric editor when the panel is double-clicked\n"
    "- Auto-trim leading & trailing whitespace in lyrics from online sources\n"
    "- Rename the 'Save to file' option to 'Save to text file' for clarity\n"
    "- Fix parsing LRC-tag-like lines as tags when in the middle of the text\n"
    "- Fix the editor's keyboard focus not starting on the actual text\n"
    "\n"
    "Version 0.6 (2021-05-23):\n"
    "- Add a context menu option to view saved lyrics for a track at any time\n"
    "- Add support for horizontal lyrics scrolling\n"
    "- Add a context menu with some very basic lyric 'auto-edits'\n"
    "- Add an option to exclude trailing brackets in titles when searching\n"
    "- Add support for the LRC 'offset' tag in timestamped lyrics\n"
    "- Add the ability to remove an 'offset' tag, updating timestamps instead\n"
    "- Add the ability to sync a line by adding/modifying an 'offset' tag\n"
    "- Change 'Open file location' button to disabled when there are no lyrics\n"
    "- Disable editor playback controls when not playing the edited track\n"
    "- Select the current line when opening the editor with synced lyrics\n"
    "- Trim surrounding whitespace from track metadata for internet searches\n"
    "- Fix the panel not updating when it should if playback is paused\n"
    "- Fix a degradation in scroll smoothness introduced in v0.5\n"
    "- Fix a potential crash when closing fb2k while the editor is open\n"
    "- Fix the editor pause/play button showing the wrong state during playback\n"
    "\n"
    "Version 0.5 (2021-04-25):\n"
    "- Add support for ColumnsUI\n"
    "- Add a preferences page for the font & colours used for the panel\n"
    "- Add a preferences page with configuration for lyric saving\n"
    "- Add the option to only auto-save synced lyrics\n"
    "- Add support for smoothly scrolling between lines of synced lyrics\n"
    "- Add wrapping for lines that do not fit into the available space\n"
    "- Change search to check the save location even if not configured to do so\n"
    "- Change save to not overwrite existing tags/files when auto-saving\n"
    "- Fix the source list selection clearing when an item is (de)activated\n"
    "- Fix the editor sometimes adding an extra blank line above the lyrics\n"
    "- Fix the panel continuing to show lyrics after playback stops\n"
    "- Fix failing to show lyrics if the panel is created during playback\n"
    "- Remove the option to not save any lyrics at all\n"
    "\n"
    "Version 0.4 (2021-04-11):\n"
    "- Add support for saving lyrics to ID3 tags\n"
    "- Add support for configuring which ID3 tags are searched or saved to\n"
    "- Add status-bar descriptions for lyric panel context menu entries\n"
    "- Add an line showing which source is currently being searched\n"
    "- Change lyric loading to not auto-reload whenever any lyrics file changes\n"
    "- Fix the release process producing incompatible *.fb2k-component archives\n"
    "- Fix config reset resetting to the last-saved value rather than the default\n"
    "- Fix a save format preview format error when playback is stopped\n"
    "- Some internal restructuring to better support future features\n"
    "\n"
    "Version 0.3 (2021-03-25):\n"
    "- Add built-in support for synchronising lines in the lyric editor\n"
    "- Add support for reading (unsynchronised) lyrics from ID3 tags\n"
    "\n"
    "Version 0.2 (2021-02-20):\n"
    "- Add support for LRC files with timestamps of the form [00.00.000]\n"
    "- Fix fallback to loading lyrics as plain text when LRC parsing fails\n"
    "- Fix saving lyrics for a track that has not yet saved any\n"
    "\n"
    "Version 0.1 (2021-01-23):\n"
    "- Initial release\n";
}

// This will prevent users from renaming your component around (important for proper troubleshooter behaviors) or loading multiple instances of it.
VALIDATE_COMPONENT_FILENAME("foo_openlyrics.dll");
