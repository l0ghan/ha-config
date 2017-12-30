About this file
======
A collection of jinja helpers to save doing stuff manually, because where's the fun in doing stuff by hand?

Auto generates the 'automation' tab
------
```automation:
  view: yes
  entities:
{% for state in states.group.all_automations.attributes.entity_id   %}    - {{ state }}
{% endfor %}```
