---
layout: default
permalink: /bugs-related-to-1-patterns/

---

# Bugs related to +-1

### 3.1. "Name"
{% highlight java %}
 Buggy: If (arg1 <= arg2) {}
 Fixed: If(arg1 <= arg2 - 1) {}
{% endhighlight %}

###### Examples: 

Closure_168 ???
 {% highlight java %}
 - if (t.getScopeDepth() <= 2) {
 
 + if (t.getScopeDepth() <= 1) {
{% endhighlight %}

Bug: [168](https://github.com/google/closure-compiler/compare/d06ac163013a3779fcec7c2f544ba99d08f69f58...b675d1da9d5f8b36849db4943f580969105901a4), Project: [Closure](https://github.com/google/closure-compiler)

### 3.2. "Name"
{% highlight java %}
 Buggy: If (arg1 <= arg2) {}
 Fixed: If(arg1 <= arg2 + 1) {}
{% endhighlight %}

###### Examples: 

### 3.3. "Name"
{% highlight java %}
 Buggy: func(listArg1, arg, listArg2)
 Fixed: func(listArg1, arg - 1, listArg2)
{% endhighlight %}

###### Examples: 

Codec_3
 {% highlight java %}
 - } else if (contains(value, index + 1, 4, "IER")) {

 + } else if (contains(value, index + 1, 3, "IER")) {
{% endhighlight %}

Bug: [3](https://github.com/apache/commons-codec/compare/d7b01850ef418b1d261cdb2029f8f85ab4031553...a5dfe5cbc95d7f3ce0b4829756690c2cb8439f4c), Project: [Codec](https://github.com/apache/commons-codec)

### 3.4. "Name"
{% highlight java %}
 Buggy: func(listArg1, arg, listArg2)
 Fixed: func(listArg1, arg + 1, listArg2)
{% endhighlight %}

###### Examples:

### 3.5. "Name"
{% highlight java %}
 Buggy: var = expr;
 Fixed: var = expr + 1;

{% endhighlight %}

###### Examples:

### 3.6. "Name"
{% highlight java %}
 Buggy: var = expr;
 Fixed: var = expr - 1;

{% endhighlight %}

###### Examples:

### 3.7. "Name"
{% highlight java %}
 Buggy: if(expr1 < expr2)
 Fixed: if(expr1 < (expr2 - 1))
{% endhighlight %}

###### Examples:

### 3.8. "Name"
{% highlight java %}
 Buggy: if (... (expr1 < expr2) ...)
 Fixed: if(expr1 < (expr2  + 1))
{% endhighlight %}

###### Examples:

### 3.9. "Name"
{% highlight java %}
 Buggy: if(expr1 < expr2)
 Fixed: if((expr1+1) < expr2)
{% endhighlight %}

###### Examples:

### 3.10. "Name"
{% highlight java %}
 Buggy: if(expr1 < expr2)
 Fixed: if((expr1 -1) < expr2))
{% endhighlight %}

###### Examples:

### 3.11. "Name"
{% highlight java %}
 Buggy: if(expr1 > expr2)
 Fixed: if(expr1 > (expr2 - 1))
{% endhighlight %}

###### Examples:

### 3.12. "Name"
{% highlight java %}
 Buggy: if(expr1 > expr2)
 Fixed: if(expr1 > (expr2 + 1))
{% endhighlight %}

###### Examples:

### 3.13. "Name"
{% highlight java %}
 Buggy: if(expr1 > expr2)
 Fixed: if((expr1 + 1) > expr2)
{% endhighlight %}

###### Examples:

### 3.14. "Name"
{% highlight java %}
 Buggy: if(expr1 > expr2)
 Fixed: if((expr1 - 1) > expr2)
{% endhighlight %}

###### Examples:

