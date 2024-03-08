---
layout: default
permalink: /misuse-of-order-operators-patterns/

---

# Misuse of order operators patterns: 


### 4.1. "Pattern_name"
{% highlight java %}
 Buggy: If (arg1 < arg2) {}
 Fixed: If(arg1 <= arg2) {}
{% endhighlight %}

###### Examples: 

Closure_62
 {% highlight java %}
 - && 0 <= charno && charno < sourceExcerpt.length()) {

 + && 0 <= charno && charno <= sourceExcerpt.length()) {
{% endhighlight %}
{% highlight java %}
pattern TEMP for
        e: LT_BIN_OP
    with
        e1, e2: EXPRESSION
    where
        e1 = e.first
        e2 = e.second
    fix
        LTE_BIN_OP [first ← e1, second ← e2]
    end
{% endhighlight %}

Bug: [62](https://github.com/google/closure-compiler/compare/1e07047234938543ea364f68ec0f29686dbc12f1...b12d1d6489329c989b15635f6f7f06681b3f6582), Project: [Closure](https://github.com/google/closure-compiler/compare)

### 4.2. "Pattern_name"

{% highlight java %}
 Buggy: If (arg1 <= arg2) {}
 Fixed: If(arg1 < arg2) {}

{% endhighlight %}

###### Examples:
Closure_73
 {% highlight java %}
 - if (c > 0x1f && c <= 0x7f) {

 + if (c > 0x1f && c < 0x7f) {

{% endhighlight %}
{% highlight java %}
pattern TEMP for
        e: LTE_BIN_OP
    with
        e1, e2: EXPRESSION
    where
        e1 = e.first
        e2 = e.second
    fix
        LT_BIN_OP [first ← e1, second ← e2]
    end
{% endhighlight %}

Bug: [73](https://github.com/google/closure-compiler/compare/760bded3242093d86611a82e81fdca302a1487f1...ee8344091722c28c9351e78dcb4155fbfddfd1af), Project: [Closure](https://github.com/google/closure-compiler/compare)

### 4.3. "Pattern_name" 
{% highlight java %}
 Buggy: If (arg1 != arg2) {}
 Fixed: If(arg1 == arg2) {}
{% endhighlight %}

###### Examples: 

Chart-1
 {% highlight java %}
- if (dataset != null) {
+ if (dataset == null) {
{% endhighlight %}
{% highlight java %}
pattern EQ_NEQ for
        e: NEQ_BIN_OP
    with
        e1, e2: EXPRESSION
    where
        e1 = e.first
        e2 = e.second
    fix
        EQ_BIN_OP [first ← e1, second ← e2]
    end
{% endhighlight %}

Bug: [73](https://github.com/google/closure-compiler/compare/760bded3242093d86611a82e81fdca302a1487f1...ee8344091722c28c9351e78dcb4155fbfddfd1af), Project: [Closure](https://github.com/google/closure-compiler/compare)


### 4.4. "Pattern_name"
{% highlight java %}
 Buggy: return false
 Fixed: return true
{% endhighlight %}






