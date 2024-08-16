---
layout: default
---
List of kinds:
{% for k in site.kinds %}
* [{{ k.title}}]({{ k.url | relative_url }})
{% endfor %}
