const char PAGE_index[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html>
<head>
<meta http-equiv='Content-Type' content='text/html; charset=UTF-8' />
<meta name='viewport' content='width=device-width, user-scalable=no' />
<title>ILIFE robot</title>
<script>function action(cmd) {
document.getElementById('message').innerHTML = cmd;
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
if (this.readyState == 4 && this.status == 200) {
document.getElementById('message').innerHTML = this.responseText;
}
};
xhttp.open('GET', '/cmd?c='+cmd, true);
xhttp.send();
}</script>
<style>
body {
  font-family: sans-serif;
  background-color: #ddd;
}
svg {
  background-color: white;
  padding: 10px;
  border: 1px solid #ccc;
  box-shadow: 0 0 10px #aaa;
}
g{cursor: pointer;} g{user-select:none;-moz-user-select:none;} g.btn:active{opacity: 0.5;}
#main {
  width: 320px;
  margin: 0 auto;
  text-align: center;
}
.pagebtn {
  border: 2px solid #171717;
  padding: 5px;
  text-decoration: none;
  color: #222;
  background-color: lightblue;
  display: block;
  margin: 5px;
}
</style>
</head><body>
<div id="main">
<h1>ILIFE robot</h1>
<svg width='52.737mm' height='79.717mm' version='1.1' viewBox='0 0 109.62584 165.7103' xmlns='http://www.w3.org/2000/svg' xmlns:cc='http://creativecommons.org/ns#' xmlns:dc='http://purl.org/dc/elements/1.1/' xmlns:rdf='http://www.w3.org/1999/02/22-rdf-syntax-ns#'>
<metadata>
<rdf:RDF>
<cc:Work rdf:about=''>
<dc:format>image/svg+xml</dc:format>
<dc:type rdf:resource='http://purl.org/dc/dcmitype/StillImage'/>
<dc:title/>
</cc:Work>
</rdf:RDF>
</metadata>
<g transform='translate(-4.2463e-6 -886.65)'>
<g class='btn' onclick="action('start')" transform='translate(-145.51 81.094)'>
<circle cx='200.33' cy='858.1' r='18.571' fill='#8ba9e6' stroke='#000' stroke-linejoin='round' stroke-width='1.5'/>
<path d='m190.27 849.33 12.411 8.997-12.545 9.0387z' fill='#fff' fill-rule='evenodd'/>
<rect x='203.62' y='849.33' width='3.0804' height='18.036' fill='#fff'/>
<rect x='208.06' y='849.33' width='3.0804' height='18.036' fill='#fff'/>
</g>
<g class='btn' onclick="action('up')">
<path d='m88.649 899.96a51.861 51.861 0 0 0 -67.674 0l17.607 17.607a27.08 27.08 0 0 1 32.466 -7e-3l17.601-17.601z' fill='#404146' stroke='#000' stroke-linejoin='round' stroke-width='1.5'/>
<path d='m48.813 905.69h12l-6-10.894z' fill='#fff' fill-rule='evenodd'/>
</g>
<g class='btn' onclick="action('right')">
<path d='m94.08 905.33-17.633 17.633a27.08 27.08 0 0 1 8e-3 32.476l17.593 17.593a51.861 51.861 0 0 0 0.0323 -67.701z' fill='#404146' stroke='#000' stroke-linejoin='round' stroke-width='1.5'/>
<path d='m88.95 933.2v12l10.894-6z' fill='#fff' fill-rule='evenodd'/>
</g>
<g class='btn' onclick="action('left')">
<path d='m15.578 905.36a51.861 51.861 0 0 0 -0.0322 67.701l17.633-17.633a27.08 27.08 0 0 1 -8e-3 -32.476l-17.593-17.593z' fill='#404146' stroke='#000' stroke-linejoin='round' stroke-width='1.5'/>
<path d='m21.052 945.2v-12l-10.894 6z' fill='#fff' fill-rule='evenodd'/>
</g>
<g class='btn' onclick="action('down')">
<path d='m71.043 960.83a27.08 27.08 0 0 1 -32.466 7e-3l-17.599 17.599a51.861 51.861 0 0 0 67.673 9.7e-4l-17.607-17.607z' fill='#404146' stroke='#000' stroke-linejoin='round' stroke-width='1.5'/>
<text x='40.579521' y='982.18628' fill='#ffffff' font-family='sans-serif' letter-spacing='0px' stroke-width='1px' word-spacing='0px' style='line-height:0%' xml:space='preserve'><tspan x='40.579521' y='982.18628' fill='#ffffff' font-size='12.5px' style='line-height:1.25'>MAX</tspan></text>
</g>
<g class='btn' onclick="action('time')" transform='translate(-145.51 81.094)'>
<rect x='213.3' y='916.08' width='33.84' height='20.708' ry='1.8404' fill='#8ba9e6' stroke='#000' stroke-linejoin='round' stroke-width='1.5'/>
<g transform='matrix(.83611 0 0 .85468 37.732 134.49)' stroke='#fff' stroke-width='.94636'>
<ellipse cx='230.22' cy='926.59' rx='6.7805' ry='6.6245' fill='#8ba9e6' stroke-linejoin='round'/>
<path d='m230.18 921.91v4.7408h3.888' fill='none'/>
</g>
</g>
<g class='btn' onclick="action('spot')" transform='translate(-145.51 81.094)'>
<rect x='146.17' y='952.41' width='29.736' height='18.197' ry='1.6172' fill='#8ba9e6' stroke='#000' stroke-linejoin='round' stroke-width='1.3181'/>
<ellipse cx='161.04' cy='961.51' rx='5.6692' ry='5.6619' fill='#8ba9e6' stroke='#fff' stroke-linejoin='round' stroke-width='.8'/>
<path d='m154.97 961.51h3.8' fill='none' stroke='#fff' stroke-width='.8'/>
<path d='m161.04 967.57v-3.8' fill='none' stroke='#fff' stroke-width='.8'/>
<path d='m167.11 961.51h-3.8' fill='none' stroke='#fff' stroke-width='.8'/>
<path d='m161.04 955.45v3.8' fill='none' stroke='#fff' stroke-width='.8'/>
<circle cx='161.04' cy='961.51' r='.75' fill='#fff'/>
</g>
<g class='btn' onclick="action('alarm')">
<rect x='7.9967' y='997.17' width='33.84' height='20.708' ry='1.8404' fill='#8ba9e6' stroke='#000' stroke-linejoin='round' stroke-width='1.5'/>
<circle cx='24.917' cy='1007.5' r='5.665' fill='#8ba9e6' stroke='#fff' stroke-linejoin='round' stroke-width='.79993'/>
<path d='m24.917 1001.4v12.255' fill='none' stroke='#8ba9e6' stroke-width='.87518px'/>
<path d='m18.789 1007.5h12.255' fill='#8ba9e6' fill-rule='evenodd' stroke='#8ba9e6' stroke-linejoin='round' stroke-width='.80411'/>
<path d='m26.354 1008.7c0.0489-0.162 0.18982-0.2644 0.18982-0.2644l1.7503-1.35c-1.3067-0.1926-2.2888-1.7963-3.3709-2.3758-0.43491-0.2167-1.3721-0.5779-2.2918-0.078-0.71933 0.778-0.60624 1.7607-0.50713 2.2364 0.59972 1.6131 1.5273 2.53 1.4409 3.8641l1.7505-1.3496s0.13484-0.1103 0.30389-0.1164c0.16887-0.01 0.27346 0.1199 0.52464-0.079 0.2562-0.1925 0.16069-0.3257 0.20977-0.4874z' fill='none' stroke='#fff' stroke-width='.8'/>
</g>
<g class='btn' onclick="action('edge')" transform='translate(-145.51 81.094)' stroke-linejoin='round'>
<rect x='224.75' y='952.41' width='29.736' height='18.197' ry='1.6172' fill='#8ba9e6' stroke='#000' stroke-width='1.3181'/>
<path d='m234.26 955.54h12.198v11.932h-12.198v-9.0352l-3.5512 2.7387' fill='none' stroke='#fff' stroke-width='.8'/>
</g>
<g class='btn' onclick="action('home')">
<rect x='39.945' y='1033.5' width='29.736' height='18.197' ry='1.6172' fill='#8ba9e6' stroke='#000' stroke-linejoin='round' stroke-width='1.3181'/>
<g stroke='#fff'>
<path d='m49.518 1049h10.75v-7.125h1.75l-7.1361-5.6851-7.2735 5.6851h1.9095z' fill='none' stroke-linejoin='round' stroke-width='.8'/>
<rect x='52.645' y='1042.3' width='4.3349' height='3.9599' ry='.73613' fill='#8ba9e6' stroke-linejoin='round' stroke-width='.5'/>
<path d='m53.844 1042.3v-1.2812' fill='none' stroke-width='.5'/>
<path d='m55.782 1042.3v-1.2813' fill='none' stroke-width='.5'/>
<path d='m54.813 1048.9v-2.6875' fill='none' stroke-width='.49995'/>
</g>
</g>
</g>
</svg>

<h2>Message</h2>
<p id="message">-</p>

<a class="pagebtn" href="/firmware">Upload new firmware</a>
<a class="pagebtn" href="/settings">Settings</a>
</div>
</body>
</html>
)=====";
