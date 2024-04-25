Common Classes



ce poate fi testat:
    Request Comments si Request Descriere
    -- acestea vor fi apelate la construcita view product si popularea labelurilor de interfat cu informatiile primite
    
 Sign In si Log In rrequest, la Log In request este nevoie de primirea la server a id-ului userului;
    pentru a ajuta la construirea ulterioara a obiectului User din dashboard printr-un request la server

to be developed:
    clasa de User/Useri ( este deja cea de userClientRequest)
    -> implementarea logicii de functionare a acestora
    -> clasa de request title (eventual adaugare de request price, sau poate fi realizat odata cu titlul)
    -> in clasa de ImageRequest este o metoda pentru implementarea stocarii imaginilor local la client
    in dashboard va fi o lista de produse care vor fi construite prin apelurile de requestimages, si request title 
    ->modificare de primire si procesare imagini cum e descris mai sus 
    ->apelul la functia de create view product page prin indexul butonului apasat din lista de butoane
    astfel se va lua si produsul care este pe aceeasi poziti in lista de produse
    si va oferi informatiile necesare : titlu, cale imagine pentru popualrea labeurilor 
    (nu cred ca este necesar memorarea descrierii si a comenatariilor in clasa de produs, cel putin nu atunci cand se deschide dashboard-ul si apelul la image request)
    
