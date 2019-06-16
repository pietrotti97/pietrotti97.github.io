---
layout: post
title:  "Billion per AGPWI"
date:   2018-08-05 00:00:00 
---
Guida per il flash del firmware su base BILLION per il router Telecom ADSL2+ Wi-Fi N, alias AGPWI o A4001N1 <img src="/media/agpwi/outer.jpg" alt="Agpwi Photo" style="float: right;" />  


Il router Telecom in questione e' quello della foto, con o senza antenne esterne. 

Per procedere con la modifica, e' consigliabile avere un adattatore seriale-usb da connettere alla board durante l'operazione.

**IMPORTANTE**: Prima di procedere con la guida, è necessario  
aver gia' sbloccato il bootloader, se non e' ancora sbloccato, segui [QUESTA](/pagine/a-router/wrt/2017/07/13/agpwi.html) guida fino al passo 8.  

><span style="color:red">**DISCLAIMER**</span>: Non mi ritengo responsabile per eventuali router brickati, eventuali gatti morti o guerre termonucleari dovute ad un malfunzionamento del suddetto prodotto.  

**Inzio della guida:**

1. Avviare il router in modalità bootloader: <a href="/media/agpwi/smontato-agpwi.jpg"><img src="/media/agpwi/smontato-agpwi.jpg" alt="Agpwi Photo" style="float: right; width:300px;" />  

    -Ponticellare Rx e Tx (i due contatti segnati in rosso)  
    -Avviare il router dal pulsante nero posteriore  
    -Staccare il ponticello tra Rx e Tx quando resta accesa una sola luce rossa.  
        
2. Assegnare un Ip statico al pc, utilizzando questi parametri:
```
        -Ip Addr: 192.168.1.2  
        -Netmask: 255.255.255.0  
        -Gateway: 192.168.1.1  
```
        
3. Connettere il pc al router con un cavo ethernet, aprire il browser ed entrare su [192.168.1.1](192.168.1.1)   <img src="/media/agpwi/cfe.jpg" alt="Agpwi Photo" style="float: right;" />  

    Si aprirà la pagina per il caricamento del firmware, che dovrebbe essere simile a questa:  
    
4. Caricare [QUESTO](/media/agpwi/Fw_Billion7800NL_2.32e_noCFE.bin) firmware, e aspettare che si riavvii il router.

    Si tratta del firmware del Billion 7800NL, che ha una board molto simile a quella di agpwi, e permette di fare praticamente di tutto col router, compresa la gestione dell'snr via webUI.  

><span style="color:red">**NOTA:**</span> Cose non funzionanti nel firmware:  
    -WiFi  
    -Porta USB
    -Led che non combaciano  

><span style="color:red">**NOTA:**</span> È possibile seguire la stessa procedura per flashare il firmware su base D-Link DSL-2750B. Di quel firmware ne esistono 2 versioni che funzionano correttamente (tranne i led). Le link entrambe:  
-[Ver. 1.0.11](/media/agpwi/dlink/DSL_2750_v1.0.11_cfe_fs_kernel)  
-[Ver. 1.0.14](/media/agpwi/dlink/DSL_2750_v1-0-14_cfe_fs_kernel.bin)  
    
Nel caso dovessero esserci errori durante il flash o il router non dovesse avviarsi correttamente, è necessario avere a portata di mano un adattatore seriale-usb.  
Effettuare queste operazioni:
<img src="/media/agpwi/serial.jpg" alt="Agpwi Photo" style="float: right; width:300px"/>

-Spegnere il Router  
-Ponticellare TX e RX del seriale, accendere il router e aspettare che l'interfaccia web di CFE parta  

-Collegare l'adattatore uart-usb al router come da foto( baudrate 115200).  
Per linux, usando screen il comando è: ```sudo screen /dev/ttyNOMEDEVICE 115200 8N1```  

-Leggere l'helper di CFE [digitare ```help``` e premere invio] e resettare la flash con il comando ```e a```  

-Riflashare il firmware dalla webUI con l'immagine precedentemente scaricata.  


><span style="color:red">**EDIT:**</span> Se dopo il riavvio il router non salva la configurazione impostata ( si riavvia sempre come se fosse la prima volta che viene acceso ):  
    -collegarsi al router con l'adattatore seriale  
    -usando l'helper di cfe ( come scritto sopra), dare il comando ```i``` ( erase persistent storage data) e dare conferma
    -riavviare con ```reset```. Ora il router dovrebbe funzionare correttamente.


    
**Fine**
 
<div id="disqus_thread"></div>
<script>

/**
*  RECOMMENDED CONFIGURATION VARIABLES: EDIT AND UNCOMMENT THE SECTION BELOW TO INSERT DYNAMIC VALUES FROM YOUR PLATFORM OR CMS.
*  LEARN WHY DEFINING THESE VARIABLES IS IMPORTANT: https://disqus.com/admin/universalcode/#configuration-variables*/
/*
var disqus_config = function () {
this.page.url = https://pietrotti97.com/pagine/a-router/mod-fw/2018/08/05/billion-dlink-agpwi.html;  // Replace PAGE_URL with your page's canonical URL variable
this.page.identifier = billionagpwi; // Replace PAGE_IDENTIFIER with your page's unique identifier variable
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
                            
