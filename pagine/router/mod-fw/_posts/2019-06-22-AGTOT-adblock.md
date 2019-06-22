---
layout: post
title:  "AdBlock su TG-789Vac"
date:   2019-02-25 00:00:00 
---
Questo post si pone l'obbiettivo di installare AdBlock direttamente sul router. 

Il router in questione è quello bianco della foto, in Italia viene distribuito da Tim o Fastweb per abbonamenti vdsl, e in [QUESTA]({% post_url 2019-02-25-AGTOT-root %}) precedente guida è stato sbloccato ed è stata installata la gui di Ansuel.
<a href="/media/agtot/router.png"><img src="/media/agtot/router.png" alt="Agpwi Photo" style="float: right;" />  


><span style="color:red">**DISCLAIMER**</span>: Non mi ritengo responsabile per eventuali router brickati, eventuali gatti morti o guerre termonucleari dovute ad un malfunzionamento del suddetto prodotto.  

><span style="color:red">**NOTA**</span>: La procedura viene eseguita su Linux  

**Procedimento:**

1. Trasferire con scp i 3 file nel modem:
        [adblock](/media/agtot/)  
        [luci-app-adblock](/media/agtot/)  
        [ssl](/media/agtot/)  
        La sintassi per scp è: ````scp filename root@192.168.1.1:/root````  

2. Loggarsi sul router come root in SSH.
        
3. I 3 file appena caricati dovrebbero  essere presenti nella cartella ````/root```` del modem.
        Installare in sequenza, adblock, poi luci-app-adblock, poi ssl

4. Dalla WebUi del modem, nella sezione ````Estensioni```` installare LuCi.
        L'interfaccia si trova sulla pagina 9080. Entrare e  loggarsi. 

5. Nella sezione Services/AdBlock, settare:

    Download Utility: Curl  
    Startup Trigger:  wan  
    Nella blacklist io ho selezionato solo adaway e adguard. Sembrano sufficienti per bloccare la maggior parte degli ads.  
    Nelle opzioni extra, aggiungere il campo ````DNS Directory```` 
    DNS directory io ho settato ````/root/adblock```` ma sarebbe consono settarla in un archivio rimovibile per evitare di finire lo storage interno di agtot.  
    Abilitare AdBlock e salvare. 
    
    **NOTA:** Nel caso in cui gli ads non dovessero scomparire, riavviare il modem!

**Fine**


<div id="disqus_thread"></div>
<script>

/**
*  RECOMMENDED CONFIGURATION VARIABLES: EDIT AND UNCOMMENT THE SECTION BELOW TO INSERT DYNAMIC VALUES FROM YOUR PLATFORM OR CMS.
*  LEARN WHY DEFINING THESE VARIABLES IS IMPORTANT: https://disqus.com/admin/universalcode/#configuration-variables*/
/*
var disqus_config = function () {
this.page.url = https://pietrotti97.com/pagine/a-router/mod-fw/2019/06/22/AGTOT-adblock.html;  // Replace PAGE_URL with your page's canonical URL variable
this.page.identifier = agtotadblock; // Replace PAGE_IDENTIFIER with your page's unique identifier variable
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




