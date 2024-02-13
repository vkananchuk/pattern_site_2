---
layout: default
permalink: /bug-fixes-patterns/
---

# Bug/fixes patterns

### 1. "Pattern_name"
 {% highlight java %}
 Buggy: If (expr1 == expr2) {}
 Fixed: If(expr1 != expr2) {}
{% endhighlight %}

### 2. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 != arg2) {}
 Fixed: If(arg1 == arg2) {}
{% endhighlight %}

### 3. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 < arg2) {}
 Fixed: If(arg1 <= arg2) {}
{% endhighlight %}

### 4. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 <= arg2) {}
 Fixed: If(arg1 < arg2) {}
{% endhighlight %}

### 5. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 <= arg2) {}
 Fixed: If(arg1 == arg2) {}
{% endhighlight %}

### 6. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 == arg2) {}
 Fixed: If(arg1 <= arg2) {}
{% endhighlight %}

### 7. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 != arg2) {}
 Fixed: If(arg1 < arg2) {}
{% endhighlight %}

### 8. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 < arg2) {}
 Fixed: If(arg1 != arg2) {}
{% endhighlight %}

### 9. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 == arg2) {}
 Fixed: If(arg1 < arg2) {}
{% endhighlight %}

### 10. "Pattern_name"
 {% highlight java %}
 Buggy: If (arg1 < arg2) {}
 Fixed: If(arg1 == arg2) {}
{% endhighlight %}

### 11. "Pattern_name"
 {% highlight java %}
 Buggy: Return true;
 Fixed: Return false;
{% endhighlight %}

### 12. "Pattern_name"
 {% highlight java %}
 Buggy: Return false;
 Fixed: Return true;
{% endhighlight %}

### 13. "Pattern_name"
 {% highlight java %}
 Buggy: func(listArg1, False, listArg2)
 Fixed: func(listArg1, True, listArg2)
{% endhighlight %}

### 14. "Pattern_name"
 {% highlight java %}
 Buggy: func(listArg1, False, listArg2)
 Fixed: func(listArg1, True, listArg2)
{% endhighlight %}

### 15. "Pattern_name"
 {% highlight java %}
 Buggy: Break;
 Fixed: Continue;
{% endhighlight %}

### 16. "Pattern_name"
 {% highlight java %}
 Buggy: Break;
 Fixed: Continue;
{% endhighlight %}

### 17. "Pattern_name"
 {% highlight java %}
 Buggy: obj.someMember
 Fixed: if(obj != null) { obj.someMember }
{% endhighlight %}

### 18. "Pattern_name"
 {% highlight java %}
 Buggy: var = expr;
 Fixed: var = expr + 1;
{% endhighlight %}

### 19. "Pattern_name"
 {% highlight java %}
 Buggy: var = expr;
 Fixed: var = expr - 1;
{% endhighlight %}

### 20. "Pattern_name"
 {% highlight java %}
 Buggy: func(listArg1, val, listArg2)
 Fixed: func(listArg1, val + 1, listArg2)
{% endhighlight %}

### 21. "Pattern_name"
 {% highlight java %}
 Buggy: func(listArg1, val, listArg2)
 Fixed: func(listArg1, val - 1, listArg2)
{% endhighlight %}

### 22. "Pattern_name"
 {% highlight java %}
 Buggy: if(expr1 < expr2)
 Fixed: if(expr1 < (expr2 - 1))
{% endhighlight %}

### 23. "Pattern_name"
 {% highlight java %}
 Buggy: if (... (expr1 < expr2) ...)
 Fixed: if(expr1 < (expr2  + 1))
{% endhighlight %}

### 24. "Pattern_name"
 {% highlight java %}
 Buggy: if(expr1 > expr2)
 Fixed: if(expr1 > (expr2 - 1))
{% endhighlight %}

...