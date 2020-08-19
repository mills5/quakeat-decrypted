# quakeat-decrypted #

Quake Arcade Tournament Edition, with dongle protection removed.

## What is this? ##

Quake Arcade Tournament Edition (quakeat) is an unreleased prototype arcade port of Quake 1. It has several unique engine modifications and cannot run in a source port.

You can read more about it here:

- http://quakearcadetournament.blogspot.com/
- https://www.quaddicted.com/quake/quake_arcade_tournament_edition
- https://www.tweaktown.com/news/36841/rare-quake-arcade-tournament-edition-on-ebay-1-of-20-/index.html

You can obtain a copy of the port by searching for its MAME hard disk image, `quakeat.chd`.

Previously, quakeat was unplayable on home computers due to a missing physical copy protection dongle that would normally be plugged into the arcade machine. Attempting to run `glquake.exe` would result in a `Security key not found` error.

This modified executable removes the dongle protection, so the port can be played on home computers.

## Instructions ##

1. Download `glquake_decrypted.exe`, and place it in the game's root directory.
2. Run `glquake_decrypted.exe`. The `-nogci` option is recommended.

If you encounter crashes or freezes, try:

- Using a Glide wrapper. [nGlide](http://www.zeus-software.com/downloads/nglide) worked for me on Windows 10. Specifically, ensure the `glide.dll`, `glide2x.dll`, and `glide3x.dll` files are alongside `glquake_decrypted.exe`.
- Running the executable with the `-nogci`, `-nosound`, or `-window` options.
- Opening `ID1/quake.rc` and commenting out all lines where a `.avi` file is passed as a parameter to `startdemos`, i.e. change `startdemos avis\lbe.avi` to `//startdemos avis\lbe.avi`, `startdemos avis\q3d-msv.avi` to `//startdemos avis\q3d-msv.avi`... ([issue](https://github.com/mills5/quakeat-decrypted/issues/2))
- Ensure the path to your quakeat directory is relatively short. i.e. `C:\Games\quakeat` ([issue](https://github.com/mills5/quakeat-decrypted/issues/2#issuecomment-675837455))

## FAQ ##

**Q: Why is `glquake_decrypted.exe` different than what is produced by `quakeat_patcher.c`?**

A: `glquake_decrypted.exe` was dumped with Scylla. The patcher was written after the fact, and works slightly differently – it modifies the original program to automagically decrypt itself and load imports when run.

## Special thanks to ##

- CyberHeg - "Breaking the shell", March 2001. http://www.woodmann.com/crackz/Tutorials/Cyberheg4.htm
- ShubNigurrath - "Removing ________ ________ dongle from Applications", September 2006 (pdf)
