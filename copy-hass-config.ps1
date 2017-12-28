$from = '\\192.168.1.65\hass\'
$to = 'C:\git\repos\ha-config'

Get-ChildItem -Path $from | % { 
  Copy-Item $_.fullname "$to" -Recurse -Force -Exclude @("home-assistant.log", "home-assistant_v2.db", "options.xml", "OZW_Log.txt", "plex.conf", "pyozw.sqlite", "YCWT2R~1", "zwcfg_0xe977f2da.xml", "zwscene.xml") 
}

Get-Date | Set-Content \\192.168.1.65\hass\lastbackup.txt