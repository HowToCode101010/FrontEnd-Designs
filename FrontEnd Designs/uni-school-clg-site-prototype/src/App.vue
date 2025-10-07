<template>
  
  <div>
    <Header/>
    <Hero/>
    <About/>
    <Departments/>
    <Courses/>
    <Faculty/>
    <Campus/>
    <Contact/>
    <Footer/>
  </div>
</template>
<script>
import Header from './components/Header.vue'
import Hero from './components/Hero.vue'
import About from './components/About.vue'
import Contact from './components/Contact.vue'
import Courses from './components/Courses.vue'
import Footer from './components/Footer.vue'
import Departments from './components/Departments.vue'
import Faculty from './components/Faculty.vue'
import Campus from './components/Campus.vue'
export default{
  components:{
    Header, Hero, About, Contact, Courses, Footer, Departments, Faculty, Campus
  }
}
</script>
