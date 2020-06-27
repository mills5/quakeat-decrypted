# quakeat-decrypted #

Quake Arcade Tournament Edition, with dongle protection removed.

## What is this? ##

Quake Arcade Tournament Edition (quakeat) is an unreleased prototype arcade port of Quake 1. It has several unique engine modifications and cannot run in a source port.

You can read more about it here:

- http://quakearcadetournament.blogspot.com/
- https://quake.fandom.com/wiki/Quake_Arcade_Tournament_Edition
- https://www.tweaktown.com/news/36841/rare-quake-arcade-tournament-edition-on-ebay-1-of-20-/index.html

You can obtain a copy of the port by searching for its MAME hard disk image, `quakeat.chd`.

Previously, quakeat was unplayable on home computers due to a missing physical copy protection dongle that would normally be plugged into the arcade machine. Attempting to run `glquake.exe` would result in a `Security key not found` error.

This modified executable removes the dongle protection, so the port can be played on home computers.

## Instructions ##

1. Download `glquake_decrypted.exe`, and place it in the game's root directory.
2. Run `glquake_decrypted.exe`. The `-nogci` option is recommended.

If you encounter crashes or freezes, try:

- Using a Glide wrapper. [nGlide](http://www.zeus-software.com/downloads/nglide) worked for me.
- Running the executable with the `-nogci`, `-nosound`, or `-window` options.

## FAQ ##

**Q: Why is `glquake_decrypted.exe` different than what is produced by `quakeat_patcher.c`?**

A: `glquake_decrypted.exe` was dumped with Scylla. The patcher was written after the fact, and works slightly differently – it modifies the original program to automagically decrypt itself and load imports when run.

## Special thanks to ##

- CyberHeg - "Breaking the shell", March 2001. http://www.woodmann.com/crackz/Tutorials/Cyberheg4.htm
- ShubNigurrath of ARTeam - "Removing Sentinel SuperPro dongle from Applications", September 2006 (pdf)