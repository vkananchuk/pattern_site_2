---
layout: default
---
List of fixes:
{% for f in site.fixes %}
* [{{ f.title }}]({{ f.url | relative_url }})
{% endfor %}
