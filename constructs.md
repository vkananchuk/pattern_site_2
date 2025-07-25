---
layout: default
---
List of constructs:
{% for c in site.constructs %}
{% assign p = c.title | find_in_collection: 'construct_usages' %}
* [{{ c.title }}]({{ c.url | relative_url }})
{%- if p != null -%}
  : [(usages)]({{ p.url | relative_url }})
{%- else -%}
  : <span class="error">Construct is never used</span>
{%- endif -%}
{% endfor %}

