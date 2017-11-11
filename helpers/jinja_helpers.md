(source: https://github.com/skalavala/smarthome/tree/master/jinja_helpers)

## Find out which zwave device checked in at when

To find out when was the last time a zwave device has communicated with the controller, run the script below
```
{%- macro zwave_check() -%}
{% for item in states.zwave %}
{%- set seconds = (((as_timestamp(now()) | int) - as_timestamp(strptime(item.attributes.receivedTS | string | truncate(19,True,'',0),'%Y-%m-%d %H:%M:%S:%f')) | int)) %}
{%- set minutes = (seconds /60) -%}
{%- set hours = (seconds /3600) -%}
{%- if seconds < 60 %}
{{ item.name.ljust(40) }} - {{ seconds }} seconds ago
{%- elif seconds > 60 and  seconds  <= 3600 %}
{{ item.name.ljust(40) }} - {{ '%0.2f' % minutes }} minutes ago
{%- elif seconds > 3600 %}
{{ item.name.ljust(40) }} - {{ '%0.2f' % (hours) }} hours ago
{%- endif %}
{%- endfor %}
{%- endmacro -%}
{% set output = zwave_check() %}
{% if output | trim == "" %}
No device has checked in the last 10 minutes.
{% else %}
Here are the devices that have checked in the last 10 minutes:
{{ output }}
{% endif %}
```