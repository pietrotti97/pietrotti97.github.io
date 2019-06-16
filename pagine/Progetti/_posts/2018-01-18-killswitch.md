---
layout: post
title:  "ADSL Kill-Switch"
date:   2017-07-13 00:00:00 +0200
---

Il kill-switch è stato costruito per ovviare ad un problema abbastanza comune.<br>La mia zona di residenza infatti è spesso soggetta a temporali, ed i cavi telefonici viaggiano ancora per via aerea.

Si rendeva quindi necessario poter scollegare velocemente il modem dalla linea adsl senza dover staccare il cavo, ma lasciando comunque operativa la linea telefonica per ricevere telefonate.

Il progetto è iniziato a partire da un filtro telefonico, che, una volta smontato, aveva lo spazio sufficiente per contenere un'interruttore.

Lo scopo era quindi quello di interrompere uno dei due cavi del doppino telefonico, e passarlo attraverso un interruttore

* Vista del Filtro aperto, a lavoro ultimato

    <a href="/media/killswitch/2.jpg"><img src="/media/killswitch/2.jpg" alt="Drawing" style="width: 250px; align=center;"/>
    <a href="/media/killswitch/3.jpg"><img src="/media/killswitch/3.jpg" alt="Drawing" style="width: 250px; align=center;"/>
      
* Foto fatta a progetto ultimato

    <a href="/media/killswitch/1.jpg"><img src="/media/killswitch/1.jpg" alt="Drawing" style="width: 350px;"/>
    
Per testare il filtro è bastato collegare il modem, prima senza filtro, poi col filtro e verificare che non ci fossero variazioni di SNR tra le due prove.

* Parametri della linea senza il filtro: 
<a href="/media/killswitch/5.jpg"><img src="/media/killswitch/5.jpg" alt="Drawing" style="width: 700; height=76.3; align=center;"/>

*    Parametri della linea con il filtro:
   <a href="/media/killswitch/4.jpg"><img src="/media/killswitch/4.jpg" alt="Drawing" style="width: 700; height=76.3; align=center;"/>

    

        
Non c'è praticamente variazione tra i valori della linea con o senza il filtro.  
Anzi, con il filtro sembra che l'SNR sia più alto.  
In ogni caso lo switch funziona alla perfezione

**That's All**


 
<div id="disqus_thread"></div>
<script>

/**
*  RECOMMENDED CONFIGURATION VARIABLES: EDIT AND UNCOMMENT THE SECTION BELOW TO INSERT DYNAMIC VALUES FROM YOUR PLATFORM OR CMS.
*  LEARN WHY DEFINING THESE VARIABLES IS IMPORTANT: https://disqus.com/admin/universalcode/#configuration-variables*/
/*
var disqus_config = function () {
this.page.url = https://pietrotti97.com/pagine/progetti/2017/07/13/killswitch.html;  // Replace PAGE_URL with your page's canonical URL variable
this.page.identifier = adslkillsw; // Replace PAGE_IDENTIFIER with your page's unique identifier variable
};
*/
(function() { // DON'T EDIT BELOW THIS LINE
var d = document, s = d.createElement('script');
s.src = 'https://pietrotti97.disqus.com/embed.js';
s.setAttribute('data-timestamp', +new Date());
(d.head || d.body).appendChild(s);
})();
</script>
<noscript>Please enable JavaScript to view the <a href="https://disqus.com/?ref_noscript">comments powered by Disqus.</a></noscript>
                            
