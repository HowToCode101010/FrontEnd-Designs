import { createApp } from 'vue'
import './style.css'
import App from './App.vue'
import { library } from '@fortawesome/fontawesome-svg-core';
import { FontAwesomeIcon } from '@fortawesome/vue-fontawesome';
import { faBars, faTimes } from '@fortawesome/free-solid-svg-icons';  // I

library.add(faBars, faTimes)

createApp(App).component('font-awesome-icon', FontAwesomeIcon).mount('#app')
