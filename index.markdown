---
# Feel free to add content and custom Front Matter to this file.
# To modify the layout, see https://jekyllrb.com/docs/themes/#overriding-theme-defaults

---

## Description

[List of bug/fixes patterns](bug-fixes-patterns/bug-fixes-patterns.md)

## Categories of LHBs

1. [Missing null checking](#missing-null-checking)
2. [False/True](#falsetrue)
3. [Misuse of order operators (<, ≤, ≥, > etc.)](#misuse-of-order-operators)
4. [Bugs related to -+1](#bugs-related-to--1)
5. [Break/Continue](#breakcontinue)
6. [Incorrect variables](#incorrect-variables)

## Detailed Descriptions

### Missing Null Checking

Bugs related to missed null checks and the consequences of accessing null objects in the result.

##### Code example: 

Buggy version: 
{% highlight java %}
 String[] array = null;
 String element = array[0]; // Accessing null element here
{% endhighlight %}

Fixed version: 

{% highlight java %}
 String[] array = null;
 String element;
 if (array != null && array.length > 0) { 
     element = array[0];
{% endhighlight %}

##### Pattern example:

{% highlight java %}
  Buggy: func(obj.someMember)
  Fixed: if(obj != null) { func(obj.someMember) }
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](missing-null-checking-patterns/missing-null-checking-patterns.md)

### False/True

Logical bugs involving the use of true instead of false and vice versa.

##### Code example: 

Buggy version: 
{% highlight java %}

{% endhighlight %}

Fixed version: 

{% highlight java %}

{% endhighlight %}

##### Pattern example:

{% highlight java %}
 Buggy: func(listArg1, True, listArg2)
 Fixed: func(listArg1, False, listArg2)

{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](false-true-patterns/false-true-patterns.md)

### Misuse of order operators
Bugs related to improper use of comparison operators in if conditions, leading to incorrect code logic.

##### Code example: 

Buggy version: 
{% highlight java %}
 
{% endhighlight %}

Fixed version: 

{% highlight java %}

{% endhighlight %}

##### Pattern example:

{% highlight java %}
 Buggy: If (arg1 <= arg2) {}
 Fixed: If(arg1 < arg2) {}
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](misuse-of-order-operators-patterns/misuse-of-order-operators-patterns.md)

### Bugs related to -+1

Bugs associated with the absence of necessary +1 or -1, or conversely, with excessive use of +1, -1. his leads to issues such as array out-of-bounds, problems with loops, various conditions, and so on.

##### Code example: 

Buggy version: 
{% highlight java %}

{% endhighlight %}

Fixed version: 

{% highlight java %}

{% endhighlight %}

##### Pattern example:

{% highlight java %}
 Buggy: func(listArg1, val, listArg2)
 Fixed: func(listArg1, val + 1, listArg2)
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](/minus-plus-one-patterns/)

### Break/Continue

Text 

##### Code example: 

Buggy version: 
{% highlight java %}

{% endhighlight %}

Fixed version: 

{% highlight java %}

{% endhighlight %}

##### Pattern example:

{% highlight java %}

{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](/missing-null-checking-patterns/)

### Incorrect variables

Text

##### Code example: 

Buggy version: 
{% highlight java %}

{% endhighlight %}

Fixed version: 

{% highlight java %}

{% endhighlight %}

##### Pattern example:

{% highlight java %}
{% endhighlight %}

[All code examples from real projects and the entire list of patterns associated with this category.](/missing-null-checking-patterns/)

---

