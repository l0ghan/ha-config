automation:
  view: yes
  entities:
{% for state in states.group.all_automations.attributes.entity_id   %}
    - {{ state }}
{% endfor %}