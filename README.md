# opaline
a small hvh cheat base for counter strike 2 before the animationgraph2 update. (april 2026 1.41.4.1)

# how to install the build it targets
head over to [DepotDownloader](https://github.com/SteamRE/DepotDownloader) and
download the windows x64 release. extract it and open cmd in the directory
containing the executable (replace `<username>` with your steam username), then run:

```bat
DepotDownloader.exe -app 730 -depot 2347770 2347771 2347774 -manifest 7643209663222864337 5302572154886330081 6328994415321406861 -username <username> -remember-password -dir "C:\cs2 legacy"
```

once it's done you should have `C:\cs2 legacy\game\bin\win64\cs2.exe`.

in a cmd window simply run:
```bat
"C:\cs2 legacy\game\bin\win64\cs2.exe" -insecure
```

and tada youre running an old version of the game, you can load in private matches and join servers running the same version
