---
layout: default
---
List of examples:
{% assign examples = site.pages | where: 'type', 'example' %}
{% for e in examples %}
* [{{ e.title}}]({{ e.url | relative_url}})
{% endfor %}
