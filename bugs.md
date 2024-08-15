---
layout: default
---
List of bugs:
{% assign bugs = site.pages | where: 'type', 'bug' %}
{% for b in bugs %}
* [{{ b.title }}]({{ b.url | relative_url }})
{% endfor %}
