---
layout: default
---
List of fixes:
{% assign fixes = site.pages | where: 'type', 'fix' %}
{% for f in fixes %}
* [{{ f.title }}]({{ f.url | relative_url }})
{% endfor %}
