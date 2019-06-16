---
layout: post
title:  "Comtrend per AGPWI"
date:   2018-08-05 00:00:00 
---
Guida per il flash del firmware su base Comtrend AR5382u per il router Telecom ADSL2+ Wi-Fi N, alias AGPWI o A4001N1 <img src="/media/agpwi/outer.jpg" alt="Agpwi Photo" style="float: right;" />  


Il router in questione e' quello della foto, con o senza antenne esterne. 

Per procedere con la modifica, e' consigliabile avere un adattatore seriale-usb da connettere alla board durante l'operazione.

**IMPORTANTE**: Prima di procedere con la guida, è necessario  
aver gia' sbloccato il bootloader, se non e' ancora sbloccato, segui [QUESTA](/pagine/a-router/wrt/2017/07/13/agpwi.html) guida fino al passo 8.  

><span style="color:red">**DISCLAIMER**</span>: Non mi ritengo responsabile per eventuali router brickati, eventuali gatti morti o guerre termonucleari dovute ad un malfunzionamento del suddetto prodotto.  

**Inzio della guida:**

1. Avviare il router in modalità bootloader col metodo del ponticello e assegnare un ip statico al pc ( vedi i primi passi della guida per sbloccare il bootloader).  

3. Connettere il pc al router con un cavo ethernet, aprire il browser ed entrare su [192.168.1.1](192.168.1.1)   <img src="/media/agpwi/cfe.jpg" alt="Agpwi Photo" style="float: right;" />  

    Si aprirà la solita pagina di cfe per il caricamento del firmware:  
    
4. Caricare prima [QUESTO](/media/agpwi/comtrend/AR-5382u-CFE-A731-406TDE-C01_R01_0623.bin) firmware ( e' il firmware base ), e aspettare che si riavvii il router.

5. A router riavviato, verificare che il firmware funzioni correttamente ( la webUI dovrebbe essere sul solito [192.168.1.1](192.168.1.1) o su [102.168.1.254](192.168.1.254) ), spegnerlo, riaccenderlo in bootloader ( sempre col metodo del ponticello), e caricare [questo](/media/agpwi/comtrend/AR-5382u-A731-406CTL-T01_R08.bin) secondo firmware.  

><span style="color:red">**NOTA**</span>: Nel caso dovesse richieder login e password per accedere alla webUI:  
    -Username: ```root```  
    -Password: ```12345```  
    


><span style="color:red">**NOTA:**</span> Cose non funzionanti nel firmware:  
    -WiFi  
    -Led che non combaciano  

Nel caso dovessero esserci errori durante il flash o il router non dovesse avviarsi correttamente, è necessario avere a portata di mano un adattatore seriale-usb.  
Effettuare queste operazioni:
<img src="/media/agpwi/serial.jpg" alt="Agpwi Photo" style="float: right; width:300px"/>

-Spegnere il Router  
-Ponticellare TX e RX del seriale, accendere il router e aspettare che l'interfaccia web di CFE parta  

-Collegare l'adattatore uart-usb al router come da foto( baudrate 115200).  
Per linux, usando screen il comando è: ```sudo screen /dev/ttyNOMEDEVICE 115200 8N1```  

-Leggere l'helper di CFE [digitare ```help``` e premere invio] e resettare la flash con il comando ```e a```  

-Riflashare il firmware dalla webUI con l'immagine precedentemente scaricata.  

**Fine**
 
<div id="disqus_thread"></div>
<script>

/**
*  RECOMMENDED CONFIGURATION VARIABLES: EDIT AND UNCOMMENT THE SECTION BELOW TO INSERT DYNAMIC VALUES FROM YOUR PLATFORM OR CMS.
*  LEARN WHY DEFINING THESE VARIABLES IS IMPORTANT: https://disqus.com/admin/universalcode/#configuration-variables*/
/*
var disqus_config = function () {
this.page.url = https://pietrotti97.com/pagine/a-router/mod-fw/2018/08/05/comtrend-agpwi.html;  // Replace PAGE_URL with your page's canonical URL variable
this.page.identifier = comtrendagpwi; // Replace PAGE_IDENTIFIER with your page's unique identifier variable
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
                            
