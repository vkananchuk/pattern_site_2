---
layout: default
permalink: /false-true-patterns/
---

# False/True Patterns: 

### 5.1. BOOLFLIP/FARG: function argument is True, should be False
 {% highlight java %}
 Buggy: func(listArg1, True, listArg2)
 Fixed: func(listArg1, False, listArg2)
{% endhighlight %}

###### Examples: 

Closure-70
 {% highlight java %}
 - jsDocParameter.getJSType(), true);

 + jsDocParameter.getJSType(), false);
{% endhighlight %} 
{% highlight java %}
pattern TEMP for
        c: call
    with
        b: BOOLEAN
    where
        b ∈ c.args
        b = True
    fix
        c [b ← False]
    End
{% endhighlight %}

Bug: [70](https://github.com/google/closure-compiler/compare/7433d30ac4cb2334d22e66299846118686efe939...ec4a34c2bd87ba54fa8770affdeeea4f3c42089b), Project: [Closure](https://github.com/google/closure-compiler)

Codec-7
{% highlight java %}
 - return StringUtils.newStringUtf8(encodeBase64(binaryData, true));

 + return StringUtils.newStringUtf8(encodeBase64(binaryData, false));
{% endhighlight %}
{% highlight java %}
pattern TEMP for
        c: call
    with
        b: BOOLEAN
    where
        b ∈ c.args
        b = True 
    fix
        c [b ← False]
    End
{% endhighlight %}

Bug: [7](https://github.com/apache/commons-codec/compare/f7966c1b374ebdd3fccb28370d9cb80a2115d807...954d995c5603b616c3c4a9ffb1823f36dd7ebcb0), Project: [Codec](https://github.com/apache/commons-codec)

### 5.2. BOOLFLIP/FARG: function result is False, should be True
{% highlight java %}
 Buggy: func(listArg1, False, listArg2)
 Fixed: func(listArg1, True, listArg2)
{% endhighlight %}

###### Examples: 

Closure-40
 {% highlight java %}
 - JsName name = getName(ns.name, false);
 - if (name != null) {

 + JsName name = getName(ns.name, true); 

 - }

{% endhighlight %}
{% highlight java %}
pattern TEMP for
        c: call
    with
        b: BOOLEAN
    where
        b ∈ c.args
        b = False
    fix
        c [b ← True]
    End
{% endhighlight %}

Bug: [40](https://github.com/google/closure-compiler/compare/a90f4b4fba37c52376d5f074729233d59ce08408...6ebc0c3d7d4da7d2cf95f53d4ea790e89d3abc7a), Project: [Closure](https://github.com/google/closure-compiler/)

### 5.3. BOOLFLIP/FRES: function result is False, should be True
{% highlight java %}
 Buggy: return true
 Fixed: return false
{% endhighlight %}

###### Examples: 

Closure-86
 {% highlight java %}
 - return true;

 + return false;
{% endhighlight %}

 {% highlight java %}
pattern FRES for
        r: RETURN_STATEMENT
    with
        b: BOOLEAN
    where
        b ∈ r.args
        b = True
    fix
        r [b ← false]
    End

{% endhighlight %}

Bug: [86](https://github.com/google/closure-compiler/compare/5cd9c1efe90dc7c1be33cd7f8c1dcbaa9225909e...0907b6618a60b2de23c8f7ec2217a37dc5e9a091), Project: [Closure](https://github.com/google/closure-compiler)

### 5.4. BOOLFLIP/FRES: function result is True, should be False
{% highlight java %}
 Buggy: return false
 Fixed: return true
{% endhighlight %}






