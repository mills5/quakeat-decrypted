# quakeat-decrypted
Quake Arcade Tournament Edition, with dongle protection removed

# What is this?

Quake Arcade Tournament Edition is an unreleased prototype arcade port of Quake 1. It has several unique engine modifications and cannot run in a source port.
Read more here:
* http://quakearcadetournament.blogspot.com/
* https://quake.fandom.com/wiki/Quake_Arcade_Tournament_Edition
* https://www.tweaktown.com/news/36841/rare-quake-arcade-tournament-edition-on-ebay-1-of-20-/index.html

You can obtain a copy of Quake Arcade Tournament by searching for "quakeat.chd", a MAME hard drive image. Until now, the game was unplayable due to a missing copy protection dongle that would normally be plugged into the machine's serial port. Attempting to run glquake.exe would result in a "Security key not found" error.

I have patched the dongle protection out of the executable, so for the first time ever, it can be played by the general public.

# How To Use
1. Download glquake_decrypted.exe and place it in the game's directory.
2. Run

# FAQ

**Q: The glquake_decrypted.exe on this repo is a different file than what is produced by quakeat_patcher.c. Why?**


A: glquake_decrypted.exe was dumped with Scylla. The patcher was written after the fact, and works slightly different - it modifies the original program to automagically decrypt itself and load imports when ran.

# Special Thanks To
CyberHeg - "Breaking the shell", March 2001 http://www.woodmann.com/crackz/Tutorials/Cyberheg4.htm
ShubNigurrath of ARTeam - "Removing Sentinel SuperPro dongle from Applications", September 2006 (pdf)