---
layout: default
---

# Missing null checking patterns: 

### 1. "Pattern_name"
 {% highlight java %}
 Buggy: func(obj.someMember)
 Fixed: if(obj != null) { func(obj.someMember) }
{% endhighlight %}

###### Examples: 

Csv_5
 {% highlight java %}
- out.append(format.getRecordSeparator());
+ final String recordSeparator = format.getRecordSeparator();
+ if (recordSeparator != null) {
+    out.append(recordSeparator);
  + }
  {% endhighlight %} 
  {% highlight java %}
  pattern TEMP for
          c: call
      with
          obj : object
      where
          obj.someMember ∈ c.args
      fix
          IF [
             condition: NOT_EQ [obj, null],
             then: c [obj.someMember]
          ]
      End
  {% endhighlight %}
 
Bug: [5](https://github.com/apache/commons-csv/compare/bf8f23c3104a137cb42e13bd69b10321cdf92135...73cc5246cf789db8f459e2f539831b6e91bedd26), Project: [Csv](https://github.com/apache/commons-csv)

### 2. "Pattern_name"
{% highlight java %}
 Buggy: res := obj.someMember
 Fixed: if(obj != null) { res := obj.someMember }
{% endhighlight %}

###### Examples: 

Csv-11
 {% highlight java %}
- final boolean emptyHeader = header.trim().isEmpty();
+ final boolean emptyHeader = header == null || header.trim().isEmpty();
{% endhighlight %}
{% highlight java %}
pattern TEMP for
        s: assignment_statement
    with
        obj : object
        var : variable
    where 
        var ∈ s.left_operand, obj.someMember ∈ s.right_operand
    fix
        IF [
             condition: NOT_EQ [obj, null],
             then: s [var, obj.someMember]
          ]
    End
{% endhighlight %}

Bug: [11](https://github.com/apache/commons-csv/compare/d3afa156e4ddf8ec76847504988e7979146d9fd6...b67524da7fd146634c7112b23e95d1d45c398b82), Project: [Csv](https://github.com/apache/commons-csv)






