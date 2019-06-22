---
layout: post
title:  "OpenWrt e Router"
date:   2017-07-13 00:00:00 +0200
---
<div id="archives">
In questa pagina raccolgo tutte le guide per le modifiche sui router.  

<ul>
  {% for category in site.categories %}
            {% capture category_name %}{{ category | first }}{% endcapture %}
                        <li><h4 >{{ "Openwrt" }}</h4>
                        {% for post in site.categories["wrt"] %}
                            <ul>
                            <li type=disc><a href="{{ site.baseurl }}{{ post.url }}">{{post.title}}</a>
                            </ul>
                        {% endfor %}
                        <p></p>
                        <li><h4 >{{ "Stock Firmware" }}</h4>
                        {% for post in site.categories["stock-fw"] %}
                            <ul>
                            <li type=disc><a href="{{ site.baseurl }}{{ post.url }}">{{post.title}}</a>
                            </ul>
                        {% endfor %}
                        <p></p>
                        <li><h4 >{{ "Firmware Alternativi" }}</h4>
                        {% for post in site.categories["mod-fw"] %}
                            <ul>
                            <li type=disc><a href="{{ site.baseurl }}{{ post.url }}">{{post.title}}</a>
                            </ul>
                        {% endfor %}
<p></p>
</div>                
