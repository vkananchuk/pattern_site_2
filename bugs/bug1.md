---
layout: default
title: bug1
pattern : p1
---

Closure-70
 {% highlight java %}
 - jsDocParameter.getJSType(), true);

 + jsDocParameter.getJSType(), false);
{% endhighlight %}

Bug: [70](https://github.com/google/closure-compiler/compare/7433d30ac4cb2334d22e66299846118686efe939...ec4a34c2bd87ba54fa8770affdeeea4f3c42089b), Project: [Closure](https://github.com/google/closure-compiler)
