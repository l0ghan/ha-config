$from = '\\pi\hass\'
$to = 'C:\Users\greg\Documents\Projects\ha-config'

Get-ChildItem -Path $from | % { 
  Copy-Item $_.fullname "$to" -Recurse -Force -Exclude @("home-assistant.log", "home-assistant_v2.db", "options.xml", "OZW_Log.txt", "plex.conf", "pyozw.sqlite", "YCWT2R~1", "zwcfg_0xe977f2da.xml", "zwscene.xml") 
}

Get-Date | Set-Content \\pi\hass\lastbackup.txt